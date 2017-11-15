"""
Densities.

"""


# probably autogen but let's not
density_functions = 'lpdf cdf lcdf lccdf rng'.split()
densities = {
    'normal': 'mu sigma',
    'exp_mod': 'mu sigma lambda',
}

def call_density_stan(name, func, pars):
    pars_args = ', '.join([f'real {p}' for p in pars.split()])
    pars_ = ', '.join(pars.split())
    yarg = 'real y, ' if func != 'rng' else ''
    y = 'y, ' if func != 'rng' else ''
    code = f'''real call_{name}_{func}({yarg}{pars_args}) {{
    return {name}_{func}({y}{pars_});
}}'''
    return code


def _maybe_extern_c(code, extern_c=True):
    if not extern_c:
        return code
    return f'''extern "C" {{
    {code}
}}'''


def call_density_stan_c(name, func, pars, extern_c=True, real='double'):
    pars_args = ', '.join([f'{real} {p}' for p in pars.split()])
    pars_ = ', '.join(pars.split())
    yarg = f'{real} y, ' if func != 'rng' else ''
    y = 'y, ' if func != 'rng' else ''
    code = _maybe_extern_c(f'''
    {real} pycmdstan_call_{name}_{func}_{real}({yarg}{pars_args}) {{
        return call_{name}_{func}({y}{pars_});
    }}''', extern_c=extern_c)
    return code


def call_all_density_stan():
    calls = [
        call_density_stan(n, f, p)
        for n, p in densities.items()
        for f in density_functions
    ]
    calls += [

    ]
    return '\n'.join(calls)


def call_all_density_stan_c(extern_c=True, real='double'):
    code = _maybe_extern_c('\n'.join([
        call_density_stan_c(n, f, p, extern_c=False, real=real)
        for n, p in densities.items()
        for f in density_functions
    ]), extern_c=extern_c)
    return code


# TODO vectorize, since scalar handled by vector[1]
# TODO generate ctypes wrappers
# TODO generate, compile load whole thing