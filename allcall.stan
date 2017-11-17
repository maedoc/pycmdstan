functions {
real call_bernoulli_lpmf(int y, int theta) {
    return bernoulli_lpmf(y | theta);
}
real call_bernoulli_cdf(int y, int theta) {
    return bernoulli_cdf(y, theta);
}
real call_bernoulli_lcdf(int y, int theta) {
    return bernoulli_lcdf(y | theta);
}
real call_bernoulli_lccdf(int y, int theta) {
    return bernoulli_lccdf(y | theta);
}
int call_bernoulli_rng(int theta) {
    return bernoulli_rng(theta);
}
int call_bernoulli_logit_rng(int alpha) {
    return bernoulli_logit_rng(alpha);
}
real call_binomial_lpmf(int y, int N, int theta) {
    return binomial_lpmf(y | N, theta);
}
real call_binomial_cdf(int y, int N, int theta) {
    return binomial_cdf(y, N, theta);
}
real call_binomial_lcdf(int y, int N, int theta) {
    return binomial_lcdf(y | N, theta);
}
real call_binomial_lccdf(int y, int N, int theta) {
    return binomial_lccdf(y | N, theta);
}
int call_binomial_rng(int N, int theta) {
    return binomial_rng(N, theta);
}
real call_neg_binomial_lpmf(int y, int alpha, int beta) {
    return neg_binomial_lpmf(y | alpha, beta);
}
real call_neg_binomial_cdf(int y, int alpha, int beta) {
    return neg_binomial_cdf(y, alpha, beta);
}
real call_neg_binomial_lcdf(int y, int alpha, int beta) {
    return neg_binomial_lcdf(y | alpha, beta);
}
real call_neg_binomial_lccdf(int y, int alpha, int beta) {
    return neg_binomial_lccdf(y | alpha, beta);
}
int call_neg_binomial_rng(int alpha, int beta) {
    return neg_binomial_rng(alpha, beta);
}
real call_neg_binomial_2_lpmf(int y, int mu, int phi) {
    return neg_binomial_2_lpmf(y | mu, phi);
}
real call_neg_binomial_2_cdf(int y, int mu, int phi) {
    return neg_binomial_2_cdf(y, mu, phi);
}
real call_neg_binomial_2_lcdf(int y, int mu, int phi) {
    return neg_binomial_2_lcdf(y | mu, phi);
}
real call_neg_binomial_2_lccdf(int y, int mu, int phi) {
    return neg_binomial_2_lccdf(y | mu, phi);
}
int call_neg_binomial_2_rng(int mu, int phi) {
    return neg_binomial_2_rng(mu, phi);
}
int call_neg_binomial_2_log_rng(int eta, int phi) {
    return neg_binomial_2_log_rng(eta, phi);
}
real call_poisson_lpmf(int y, int lambda) {
    return poisson_lpmf(y | lambda);
}
real call_poisson_cdf(int y, int lambda) {
    return poisson_cdf(y, lambda);
}
real call_poisson_lcdf(int y, int lambda) {
    return poisson_lcdf(y | lambda);
}
real call_poisson_lccdf(int y, int lambda) {
    return poisson_lccdf(y | lambda);
}
int call_poisson_rng(int lambda) {
    return poisson_rng(lambda);
}
int call_poisson_log_rng(int alpha) {
    return poisson_log_rng(alpha);
}
real call_normal_lpdf(real y, real mu, real sigma) {
    return normal_lpdf(y | mu, sigma);
}
real call_normal_cdf(real y, real mu, real sigma) {
    return normal_cdf(y, mu, sigma);
}
real call_normal_lcdf(real y, real mu, real sigma) {
    return normal_lcdf(y | mu, sigma);
}
real call_normal_lccdf(real y, real mu, real sigma) {
    return normal_lccdf(y | mu, sigma);
}
real call_normal_rng(real mu, real sigma) {
    return normal_rng(mu, sigma);
}
real call_exp_mod_normal_lpdf(real y, real mu, real sigma, real lambda) {
    return exp_mod_normal_lpdf(y | mu, sigma, lambda);
}
real call_exp_mod_normal_cdf(real y, real mu, real sigma, real lambda) {
    return exp_mod_normal_cdf(y, mu, sigma, lambda);
}
real call_exp_mod_normal_lcdf(real y, real mu, real sigma, real lambda) {
    return exp_mod_normal_lcdf(y | mu, sigma, lambda);
}
real call_exp_mod_normal_lccdf(real y, real mu, real sigma, real lambda) {
    return exp_mod_normal_lccdf(y | mu, sigma, lambda);
}
real call_exp_mod_normal_rng(real mu, real sigma, real lambda) {
    return exp_mod_normal_rng(mu, sigma, lambda);
}
real call_skew_normal_lpdf(real y, real xi, real omega, real alpha) {
    return skew_normal_lpdf(y | xi, omega, alpha);
}
real call_skew_normal_cdf(real y, real xi, real omega, real alpha) {
    return skew_normal_cdf(y, xi, omega, alpha);
}
real call_skew_normal_lcdf(real y, real xi, real omega, real alpha) {
    return skew_normal_lcdf(y | xi, omega, alpha);
}
real call_skew_normal_lccdf(real y, real xi, real omega, real alpha) {
    return skew_normal_lccdf(y | xi, omega, alpha);
}
real call_skew_normal_rng(real xi, real omega, real alpha) {
    return skew_normal_rng(xi, omega, alpha);
}
real call_student_t_lpdf(real y, real nu, real mu, real sigma) {
    return student_t_lpdf(y | nu, mu, sigma);
}
real call_student_t_cdf(real y, real nu, real mu, real sigma) {
    return student_t_cdf(y, nu, mu, sigma);
}
real call_student_t_lcdf(real y, real nu, real mu, real sigma) {
    return student_t_lcdf(y | nu, mu, sigma);
}
real call_student_t_lccdf(real y, real nu, real mu, real sigma) {
    return student_t_lccdf(y | nu, mu, sigma);
}
real call_student_t_rng(real nu, real mu, real sigma) {
    return student_t_rng(nu, mu, sigma);
}
real call_cauchy_lpdf(real y, real mu, real sigma) {
    return cauchy_lpdf(y | mu, sigma);
}
real call_cauchy_cdf(real y, real mu, real sigma) {
    return cauchy_cdf(y, mu, sigma);
}
real call_cauchy_lcdf(real y, real mu, real sigma) {
    return cauchy_lcdf(y | mu, sigma);
}
real call_cauchy_lccdf(real y, real mu, real sigma) {
    return cauchy_lccdf(y | mu, sigma);
}
real call_cauchy_rng(real mu, real sigma) {
    return cauchy_rng(mu, sigma);
}
real call_double_exponential_lpdf(real y, real mu, real sigma) {
    return double_exponential_lpdf(y | mu, sigma);
}
real call_double_exponential_cdf(real y, real mu, real sigma) {
    return double_exponential_cdf(y, mu, sigma);
}
real call_double_exponential_lcdf(real y, real mu, real sigma) {
    return double_exponential_lcdf(y | mu, sigma);
}
real call_double_exponential_lccdf(real y, real mu, real sigma) {
    return double_exponential_lccdf(y | mu, sigma);
}
real call_double_exponential_rng(real mu, real sigma) {
    return double_exponential_rng(mu, sigma);
}
real call_logistic_lpdf(real y, real mu, real sigma) {
    return logistic_lpdf(y | mu, sigma);
}
real call_logistic_cdf(real y, real mu, real sigma) {
    return logistic_cdf(y, mu, sigma);
}
real call_logistic_lcdf(real y, real mu, real sigma) {
    return logistic_lcdf(y | mu, sigma);
}
real call_logistic_lccdf(real y, real mu, real sigma) {
    return logistic_lccdf(y | mu, sigma);
}
real call_logistic_rng(real mu, real sigma) {
    return logistic_rng(mu, sigma);
}
real call_gumbel_lpdf(real y, real mu, real beta) {
    return gumbel_lpdf(y | mu, beta);
}
real call_gumbel_cdf(real y, real mu, real beta) {
    return gumbel_cdf(y, mu, beta);
}
real call_gumbel_lcdf(real y, real mu, real beta) {
    return gumbel_lcdf(y | mu, beta);
}
real call_gumbel_lccdf(real y, real mu, real beta) {
    return gumbel_lccdf(y | mu, beta);
}
real call_gumbel_rng(real mu, real beta) {
    return gumbel_rng(mu, beta);
}
real call_lognormal_lpdf(real y, real mu, real sigma) {
    return lognormal_lpdf(y | mu, sigma);
}
real call_lognormal_cdf(real y, real mu, real sigma) {
    return lognormal_cdf(y, mu, sigma);
}
real call_lognormal_lcdf(real y, real mu, real sigma) {
    return lognormal_lcdf(y | mu, sigma);
}
real call_lognormal_lccdf(real y, real mu, real sigma) {
    return lognormal_lccdf(y | mu, sigma);
}
real call_lognormal_rng(real mu, real sigma) {
    return lognormal_rng(mu, sigma);
}
real call_chi_square_lpdf(real y, real nu) {
    return chi_square_lpdf(y | nu);
}
real call_chi_square_cdf(real y, real nu) {
    return chi_square_cdf(y, nu);
}
real call_chi_square_lcdf(real y, real nu) {
    return chi_square_lcdf(y | nu);
}
real call_chi_square_lccdf(real y, real nu) {
    return chi_square_lccdf(y | nu);
}
real call_chi_square_rng(real nu) {
    return chi_square_rng(nu);
}
real call_inv_chi_square_lpdf(real y, real nu) {
    return inv_chi_square_lpdf(y | nu);
}
real call_inv_chi_square_cdf(real y, real nu) {
    return inv_chi_square_cdf(y, nu);
}
real call_inv_chi_square_lcdf(real y, real nu) {
    return inv_chi_square_lcdf(y | nu);
}
real call_inv_chi_square_lccdf(real y, real nu) {
    return inv_chi_square_lccdf(y | nu);
}
real call_inv_chi_square_rng(real nu) {
    return inv_chi_square_rng(nu);
}
real call_scaled_inv_chi_square_lpdf(real y, real nu, real sigma) {
    return scaled_inv_chi_square_lpdf(y | nu, sigma);
}
real call_scaled_inv_chi_square_cdf(real y, real nu, real sigma) {
    return scaled_inv_chi_square_cdf(y, nu, sigma);
}
real call_scaled_inv_chi_square_lcdf(real y, real nu, real sigma) {
    return scaled_inv_chi_square_lcdf(y | nu, sigma);
}
real call_scaled_inv_chi_square_lccdf(real y, real nu, real sigma) {
    return scaled_inv_chi_square_lccdf(y | nu, sigma);
}
real call_scaled_inv_chi_square_rng(real nu, real sigma) {
    return scaled_inv_chi_square_rng(nu, sigma);
}
real call_exponential_lpdf(real y, real beta) {
    return exponential_lpdf(y | beta);
}
real call_exponential_cdf(real y, real beta) {
    return exponential_cdf(y, beta);
}
real call_exponential_lcdf(real y, real beta) {
    return exponential_lcdf(y | beta);
}
real call_exponential_lccdf(real y, real beta) {
    return exponential_lccdf(y | beta);
}
real call_exponential_rng(real beta) {
    return exponential_rng(beta);
}
real call_gamma_lpdf(real y, real alpha, real beta) {
    return gamma_lpdf(y | alpha, beta);
}
real call_gamma_cdf(real y, real alpha, real beta) {
    return gamma_cdf(y, alpha, beta);
}
real call_gamma_lcdf(real y, real alpha, real beta) {
    return gamma_lcdf(y | alpha, beta);
}
real call_gamma_lccdf(real y, real alpha, real beta) {
    return gamma_lccdf(y | alpha, beta);
}
real call_gamma_rng(real alpha, real beta) {
    return gamma_rng(alpha, beta);
}
real call_inv_gamma_lpdf(real y, real alpha, real beta) {
    return inv_gamma_lpdf(y | alpha, beta);
}
real call_inv_gamma_cdf(real y, real alpha, real beta) {
    return inv_gamma_cdf(y, alpha, beta);
}
real call_inv_gamma_lcdf(real y, real alpha, real beta) {
    return inv_gamma_lcdf(y | alpha, beta);
}
real call_inv_gamma_lccdf(real y, real alpha, real beta) {
    return inv_gamma_lccdf(y | alpha, beta);
}
real call_inv_gamma_rng(real alpha, real beta) {
    return inv_gamma_rng(alpha, beta);
}
real call_weibull_lpdf(real y, real alpha, real sigma) {
    return weibull_lpdf(y | alpha, sigma);
}
real call_weibull_cdf(real y, real alpha, real sigma) {
    return weibull_cdf(y, alpha, sigma);
}
real call_weibull_lcdf(real y, real alpha, real sigma) {
    return weibull_lcdf(y | alpha, sigma);
}
real call_weibull_lccdf(real y, real alpha, real sigma) {
    return weibull_lccdf(y | alpha, sigma);
}
real call_weibull_rng(real alpha, real sigma) {
    return weibull_rng(alpha, sigma);
}
real call_frechet_lpdf(real y, real alpha, real sigma) {
    return frechet_lpdf(y | alpha, sigma);
}
real call_frechet_cdf(real y, real alpha, real sigma) {
    return frechet_cdf(y, alpha, sigma);
}
real call_frechet_lcdf(real y, real alpha, real sigma) {
    return frechet_lcdf(y | alpha, sigma);
}
real call_frechet_lccdf(real y, real alpha, real sigma) {
    return frechet_lccdf(y | alpha, sigma);
}
real call_frechet_rng(real alpha, real sigma) {
    return frechet_rng(alpha, sigma);
}
real call_rayleigh_lpdf(real y, real sigma) {
    return rayleigh_lpdf(y | sigma);
}
real call_rayleigh_cdf(real y, real sigma) {
    return rayleigh_cdf(y, sigma);
}
real call_rayleigh_lcdf(real y, real sigma) {
    return rayleigh_lcdf(y | sigma);
}
real call_rayleigh_lccdf(real y, real sigma) {
    return rayleigh_lccdf(y | sigma);
}
real call_rayleigh_rng(real sigma) {
    return rayleigh_rng(sigma);
}
real call_wiener_lpdf(real y, real alpha, real tau, real beta, real delta) {
    return wiener_lpdf(y | alpha, tau, beta, delta);
}
real call_pareto_lpdf(real y, real y_min, real alpha) {
    return pareto_lpdf(y | y_min, alpha);
}
real call_pareto_cdf(real y, real y_min, real alpha) {
    return pareto_cdf(y, y_min, alpha);
}
real call_pareto_lcdf(real y, real y_min, real alpha) {
    return pareto_lcdf(y | y_min, alpha);
}
real call_pareto_lccdf(real y, real y_min, real alpha) {
    return pareto_lccdf(y | y_min, alpha);
}
real call_pareto_rng(real y_min, real alpha) {
    return pareto_rng(y_min, alpha);
}
real call_pareto_type_2_lpdf(real y, real mu, real lambda, real alpha) {
    return pareto_type_2_lpdf(y | mu, lambda, alpha);
}
real call_pareto_type_2_cdf(real y, real mu, real lambda, real alpha) {
    return pareto_type_2_cdf(y, mu, lambda, alpha);
}
real call_pareto_type_2_lcdf(real y, real mu, real lambda, real alpha) {
    return pareto_type_2_lcdf(y | mu, lambda, alpha);
}
real call_pareto_type_2_lccdf(real y, real mu, real lambda, real alpha) {
    return pareto_type_2_lccdf(y | mu, lambda, alpha);
}
real call_pareto_type_2_rng(real mu, real lambda, real alpha) {
    return pareto_type_2_rng(mu, lambda, alpha);
}
real call_beta_lpdf(real y, real alpha, real beta) {
    return beta_lpdf(y | alpha, beta);
}
real call_beta_cdf(real y, real alpha, real beta) {
    return beta_cdf(y, alpha, beta);
}
real call_beta_lcdf(real y, real alpha, real beta) {
    return beta_lcdf(y | alpha, beta);
}
real call_beta_lccdf(real y, real alpha, real beta) {
    return beta_lccdf(y | alpha, beta);
}
real call_beta_rng(real alpha, real beta) {
    return beta_rng(alpha, beta);
}
real call_von_mises_lpdf(real y, real mu, real kappa) {
    return von_mises_lpdf(y | mu, kappa);
}
real call_von_mises_rng(real mu, real kappa) {
    return von_mises_rng(mu, kappa);
}
real call_uniform_lpdf(real y, real alpha, real beta) {
    return uniform_lpdf(y | alpha, beta);
}
real call_uniform_cdf(real y, real alpha, real beta) {
    return uniform_cdf(y, alpha, beta);
}
real call_uniform_lcdf(real y, real alpha, real beta) {
    return uniform_lcdf(y | alpha, beta);
}
real call_uniform_lccdf(real y, real alpha, real beta) {
    return uniform_lccdf(y | alpha, beta);
}
real call_uniform_rng(real alpha, real beta) {
    return uniform_rng(alpha, beta);
}
}
