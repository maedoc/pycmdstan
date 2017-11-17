"""
Densities.

python3 pycmdstan/densities.py call_all_density_stan > allcall.stan
stanc allcall.stan

python3 pycmdstan/densities.py call_all_density_pybind > allcall_methods.hpp

"""


# probably autogen but let's not
density_functions = 'lpdf cdf lcdf lccdf rng'.split()
discrete = ('bernoulli bernoulli_logit binomial binomial_logit beta_binomial'
    ' neg_binomial neg_binomial_2 neg_binomial_2_log poisson poisson_log'
    ).split()
densities = {
    # in order from stan ref 2.17
    'bernoulli': 'theta',
    'bernoulli_logit': ('alpha', 'lpmf rng'),
    'binomial': 'N theta', # N is int
    'binomial_logit': ('N alpha', 'lpmf'),
    #'beta_binomial': 'alpha beta',
    # 'categorical': not real valued
    # ordered logistic
    'neg_binomial': 'alpha beta',
    'neg_binomial_2': 'mu phi',
    'neg_binomial_2_log': ('eta phi', 'lpmf rng'),
    'poisson': 'lambda',
    'poisson_log': ('alpha', 'lpmf rng'),
    #'multinomial': ('theta')
    'normal': 'mu sigma',
    'exp_mod_normal': 'mu sigma lambda',
    'skew_normal': 'xi omega alpha',
    'student_t': 'nu mu sigma',
    'cauchy': 'mu sigma',
    'double_exponential': 'mu sigma',
    'logistic': 'mu sigma',
    'gumbel': 'mu beta',
    'lognormal': 'mu sigma',
    'chi_square': 'nu',
    'inv_chi_square': 'nu',
    'scaled_inv_chi_square': 'nu sigma',
    'exponential': 'beta',
    'gamma': 'alpha beta',
    'inv_gamma': 'alpha beta',
    'weibull': 'alpha sigma',
    'frechet': 'alpha sigma',
    'rayleigh': 'sigma',
    'wiener': ('alpha tau beta delta', 'lpdf'),
    'pareto': 'y_min alpha',
    'pareto_type_2': 'mu lambda alpha',
    'beta': 'alpha beta',
    'von_mises': ('mu kappa', 'lpdf rng'),
    'uniform': 'alpha beta',
    # and then the wild distributions
}

def call_density_stan(name, func, pars):
    if (name in discrete) and func == 'lpdf':
        func = 'lpmf'
    # print(name, func)
    vtype = 'int' if name in discrete else 'real'
    pars_args = ', '.join([f'{vtype} {p}' for p in pars.split()])
    pars_ = ', '.join(pars.split())
    yarg = f'{vtype} y, ' if func != 'rng' else ''
    if func == 'rng':
        y = ''
    elif func == 'cdf':
        y = 'y, '
    else:
        y = 'y | '
    rettype = 'int' if func == 'rng' and name in discrete else 'real'
    code = f'''{rettype} call_{name}_{func}({yarg}{pars_args}) {{
    return {name}_{func}({y}{pars_});
}}'''
    return code


def call_density_pybind(name, func, pars, real='double'):
    if (name in discrete) and func == 'lpdf':
        func = 'lpmf'
    # print(name, func)
    vtype = 'int' if name in discrete else real
    pars_args = ', '.join([f'{vtype} {p}' for p in pars.split()])
    pars_ = ', '.join(pars.split())
    # decl args
    yarg = f'{vtype} y, ' if func != 'rng' else ''
    yargr = f', boost::ecuyer1988 & r' if func == 'rng' else ''
    # call args
    if func == 'rng':
        y = ''
        yr = ', r'
    else:
        y = 'y, '
        yr = ''
    # pybind module function def
    code = f'''
    m.def("{name}_{func}",
      py::vectorize([]({yarg}{pars_args}{yargr}) {{
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_{name}_{func}({y}{pars_}{yr}, &std::cout);
      }}),
      "{func} for {name} distribution.");'''
    return code


def _df_avail(p):
    if isinstance(p, tuple):
        return p[1].split()
    return density_functions


def _params(p):
    if isinstance(p, tuple):
        return p[0]
    return p


def call_all_density_stan():
    calls = [
        'functions {'
    ]
    calls += [
        call_density_stan(n, f, _params(p))
        for n, p in densities.items()
        for f in density_functions
        if f in _df_avail(p)
    ]
    calls += [
        '}'
    ]
    return '\n'.join(calls)


def call_all_density_pybind(real='double'):
    calls = [
        call_density_pybind(n, f, _params(p))
        for n, p in densities.items()
        for f in density_functions
        if f in _df_avail(p)
    ]
    return '\n'.join(calls)


# TODO vectorize, since scalar handled by vector[1]
# TODO generate ctypes wrappers
# TODO generate, compile load whole thing

if __name__ == '__main__':
    import fire; fire.Fire()
