
    m.def("bernoulli_lpmf",
      py::vectorize([](int y, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_bernoulli_lpmf(y, theta, &std::cout);
      }),
      "lpmf for bernoulli distribution.");

    m.def("bernoulli_cdf",
      py::vectorize([](int y, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_bernoulli_cdf(y, theta, &std::cout);
      }),
      "cdf for bernoulli distribution.");

    m.def("bernoulli_lcdf",
      py::vectorize([](int y, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_bernoulli_lcdf(y, theta, &std::cout);
      }),
      "lcdf for bernoulli distribution.");

    m.def("bernoulli_lccdf",
      py::vectorize([](int y, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_bernoulli_lccdf(y, theta, &std::cout);
      }),
      "lccdf for bernoulli distribution.");

    m.def("bernoulli_rng",
      py::vectorize([](int theta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_bernoulli_rng(theta, r, &std::cout);
      }),
      "rng for bernoulli distribution.");

    m.def("bernoulli_logit_rng",
      py::vectorize([](int alpha, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_bernoulli_logit_rng(alpha, r, &std::cout);
      }),
      "rng for bernoulli_logit distribution.");

    m.def("binomial_lpmf",
      py::vectorize([](int y, int N, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_binomial_lpmf(y, N, theta, &std::cout);
      }),
      "lpmf for binomial distribution.");

    m.def("binomial_cdf",
      py::vectorize([](int y, int N, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_binomial_cdf(y, N, theta, &std::cout);
      }),
      "cdf for binomial distribution.");

    m.def("binomial_lcdf",
      py::vectorize([](int y, int N, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_binomial_lcdf(y, N, theta, &std::cout);
      }),
      "lcdf for binomial distribution.");

    m.def("binomial_lccdf",
      py::vectorize([](int y, int N, int theta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_binomial_lccdf(y, N, theta, &std::cout);
      }),
      "lccdf for binomial distribution.");

    m.def("binomial_rng",
      py::vectorize([](int N, int theta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_binomial_rng(N, theta, r, &std::cout);
      }),
      "rng for binomial distribution.");

    m.def("neg_binomial_lpmf",
      py::vectorize([](int y, int alpha, int beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_lpmf(y, alpha, beta, &std::cout);
      }),
      "lpmf for neg_binomial distribution.");

    m.def("neg_binomial_cdf",
      py::vectorize([](int y, int alpha, int beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_cdf(y, alpha, beta, &std::cout);
      }),
      "cdf for neg_binomial distribution.");

    m.def("neg_binomial_lcdf",
      py::vectorize([](int y, int alpha, int beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_lcdf(y, alpha, beta, &std::cout);
      }),
      "lcdf for neg_binomial distribution.");

    m.def("neg_binomial_lccdf",
      py::vectorize([](int y, int alpha, int beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_lccdf(y, alpha, beta, &std::cout);
      }),
      "lccdf for neg_binomial distribution.");

    m.def("neg_binomial_rng",
      py::vectorize([](int alpha, int beta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_rng(alpha, beta, r, &std::cout);
      }),
      "rng for neg_binomial distribution.");

    m.def("neg_binomial_2_lpmf",
      py::vectorize([](int y, int mu, int phi) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_2_lpmf(y, mu, phi, &std::cout);
      }),
      "lpmf for neg_binomial_2 distribution.");

    m.def("neg_binomial_2_cdf",
      py::vectorize([](int y, int mu, int phi) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_2_cdf(y, mu, phi, &std::cout);
      }),
      "cdf for neg_binomial_2 distribution.");

    m.def("neg_binomial_2_lcdf",
      py::vectorize([](int y, int mu, int phi) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_2_lcdf(y, mu, phi, &std::cout);
      }),
      "lcdf for neg_binomial_2 distribution.");

    m.def("neg_binomial_2_lccdf",
      py::vectorize([](int y, int mu, int phi) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_2_lccdf(y, mu, phi, &std::cout);
      }),
      "lccdf for neg_binomial_2 distribution.");

    m.def("neg_binomial_2_rng",
      py::vectorize([](int mu, int phi, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_2_rng(mu, phi, r, &std::cout);
      }),
      "rng for neg_binomial_2 distribution.");

    m.def("neg_binomial_2_log_rng",
      py::vectorize([](int eta, int phi, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_neg_binomial_2_log_rng(eta, phi, r, &std::cout);
      }),
      "rng for neg_binomial_2_log distribution.");

    m.def("poisson_lpmf",
      py::vectorize([](int y, int lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_poisson_lpmf(y, lambda, &std::cout);
      }),
      "lpmf for poisson distribution.");

    m.def("poisson_cdf",
      py::vectorize([](int y, int lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_poisson_cdf(y, lambda, &std::cout);
      }),
      "cdf for poisson distribution.");

    m.def("poisson_lcdf",
      py::vectorize([](int y, int lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_poisson_lcdf(y, lambda, &std::cout);
      }),
      "lcdf for poisson distribution.");

    m.def("poisson_lccdf",
      py::vectorize([](int y, int lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_poisson_lccdf(y, lambda, &std::cout);
      }),
      "lccdf for poisson distribution.");

    m.def("poisson_rng",
      py::vectorize([](int lambda, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_poisson_rng(lambda, r, &std::cout);
      }),
      "rng for poisson distribution.");

    m.def("poisson_log_rng",
      py::vectorize([](int alpha, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_poisson_log_rng(alpha, r, &std::cout);
      }),
      "rng for poisson_log distribution.");

    m.def("normal_lpdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_normal_lpdf(y, mu, sigma, &std::cout);
      }),
      "lpdf for normal distribution.");

    m.def("normal_cdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_normal_cdf(y, mu, sigma, &std::cout);
      }),
      "cdf for normal distribution.");

    m.def("normal_lcdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_normal_lcdf(y, mu, sigma, &std::cout);
      }),
      "lcdf for normal distribution.");

    m.def("normal_lccdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_normal_lccdf(y, mu, sigma, &std::cout);
      }),
      "lccdf for normal distribution.");

    m.def("normal_rng",
      py::vectorize([](double mu, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_normal_rng(mu, sigma, r, &std::cout);
      }),
      "rng for normal distribution.");

    m.def("exp_mod_normal_lpdf",
      py::vectorize([](double y, double mu, double sigma, double lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exp_mod_normal_lpdf(y, mu, sigma, lambda, &std::cout);
      }),
      "lpdf for exp_mod_normal distribution.");

    m.def("exp_mod_normal_cdf",
      py::vectorize([](double y, double mu, double sigma, double lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exp_mod_normal_cdf(y, mu, sigma, lambda, &std::cout);
      }),
      "cdf for exp_mod_normal distribution.");

    m.def("exp_mod_normal_lcdf",
      py::vectorize([](double y, double mu, double sigma, double lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exp_mod_normal_lcdf(y, mu, sigma, lambda, &std::cout);
      }),
      "lcdf for exp_mod_normal distribution.");

    m.def("exp_mod_normal_lccdf",
      py::vectorize([](double y, double mu, double sigma, double lambda) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exp_mod_normal_lccdf(y, mu, sigma, lambda, &std::cout);
      }),
      "lccdf for exp_mod_normal distribution.");

    m.def("exp_mod_normal_rng",
      py::vectorize([](double mu, double sigma, double lambda, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exp_mod_normal_rng(mu, sigma, lambda, r, &std::cout);
      }),
      "rng for exp_mod_normal distribution.");

    m.def("skew_normal_lpdf",
      py::vectorize([](double y, double xi, double omega, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_skew_normal_lpdf(y, xi, omega, alpha, &std::cout);
      }),
      "lpdf for skew_normal distribution.");

    m.def("skew_normal_cdf",
      py::vectorize([](double y, double xi, double omega, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_skew_normal_cdf(y, xi, omega, alpha, &std::cout);
      }),
      "cdf for skew_normal distribution.");

    m.def("skew_normal_lcdf",
      py::vectorize([](double y, double xi, double omega, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_skew_normal_lcdf(y, xi, omega, alpha, &std::cout);
      }),
      "lcdf for skew_normal distribution.");

    m.def("skew_normal_lccdf",
      py::vectorize([](double y, double xi, double omega, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_skew_normal_lccdf(y, xi, omega, alpha, &std::cout);
      }),
      "lccdf for skew_normal distribution.");

    m.def("skew_normal_rng",
      py::vectorize([](double xi, double omega, double alpha, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_skew_normal_rng(xi, omega, alpha, r, &std::cout);
      }),
      "rng for skew_normal distribution.");

    m.def("student_t_lpdf",
      py::vectorize([](double y, double nu, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_student_t_lpdf(y, nu, mu, sigma, &std::cout);
      }),
      "lpdf for student_t distribution.");

    m.def("student_t_cdf",
      py::vectorize([](double y, double nu, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_student_t_cdf(y, nu, mu, sigma, &std::cout);
      }),
      "cdf for student_t distribution.");

    m.def("student_t_lcdf",
      py::vectorize([](double y, double nu, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_student_t_lcdf(y, nu, mu, sigma, &std::cout);
      }),
      "lcdf for student_t distribution.");

    m.def("student_t_lccdf",
      py::vectorize([](double y, double nu, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_student_t_lccdf(y, nu, mu, sigma, &std::cout);
      }),
      "lccdf for student_t distribution.");

    m.def("student_t_rng",
      py::vectorize([](double nu, double mu, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_student_t_rng(nu, mu, sigma, r, &std::cout);
      }),
      "rng for student_t distribution.");

    m.def("cauchy_lpdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_cauchy_lpdf(y, mu, sigma, &std::cout);
      }),
      "lpdf for cauchy distribution.");

    m.def("cauchy_cdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_cauchy_cdf(y, mu, sigma, &std::cout);
      }),
      "cdf for cauchy distribution.");

    m.def("cauchy_lcdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_cauchy_lcdf(y, mu, sigma, &std::cout);
      }),
      "lcdf for cauchy distribution.");

    m.def("cauchy_lccdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_cauchy_lccdf(y, mu, sigma, &std::cout);
      }),
      "lccdf for cauchy distribution.");

    m.def("cauchy_rng",
      py::vectorize([](double mu, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_cauchy_rng(mu, sigma, r, &std::cout);
      }),
      "rng for cauchy distribution.");

    m.def("double_exponential_lpdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_double_exponential_lpdf(y, mu, sigma, &std::cout);
      }),
      "lpdf for double_exponential distribution.");

    m.def("double_exponential_cdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_double_exponential_cdf(y, mu, sigma, &std::cout);
      }),
      "cdf for double_exponential distribution.");

    m.def("double_exponential_lcdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_double_exponential_lcdf(y, mu, sigma, &std::cout);
      }),
      "lcdf for double_exponential distribution.");

    m.def("double_exponential_lccdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_double_exponential_lccdf(y, mu, sigma, &std::cout);
      }),
      "lccdf for double_exponential distribution.");

    m.def("double_exponential_rng",
      py::vectorize([](double mu, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_double_exponential_rng(mu, sigma, r, &std::cout);
      }),
      "rng for double_exponential distribution.");

    m.def("logistic_lpdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_logistic_lpdf(y, mu, sigma, &std::cout);
      }),
      "lpdf for logistic distribution.");

    m.def("logistic_cdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_logistic_cdf(y, mu, sigma, &std::cout);
      }),
      "cdf for logistic distribution.");

    m.def("logistic_lcdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_logistic_lcdf(y, mu, sigma, &std::cout);
      }),
      "lcdf for logistic distribution.");

    m.def("logistic_lccdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_logistic_lccdf(y, mu, sigma, &std::cout);
      }),
      "lccdf for logistic distribution.");

    m.def("logistic_rng",
      py::vectorize([](double mu, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_logistic_rng(mu, sigma, r, &std::cout);
      }),
      "rng for logistic distribution.");

    m.def("gumbel_lpdf",
      py::vectorize([](double y, double mu, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gumbel_lpdf(y, mu, beta, &std::cout);
      }),
      "lpdf for gumbel distribution.");

    m.def("gumbel_cdf",
      py::vectorize([](double y, double mu, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gumbel_cdf(y, mu, beta, &std::cout);
      }),
      "cdf for gumbel distribution.");

    m.def("gumbel_lcdf",
      py::vectorize([](double y, double mu, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gumbel_lcdf(y, mu, beta, &std::cout);
      }),
      "lcdf for gumbel distribution.");

    m.def("gumbel_lccdf",
      py::vectorize([](double y, double mu, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gumbel_lccdf(y, mu, beta, &std::cout);
      }),
      "lccdf for gumbel distribution.");

    m.def("gumbel_rng",
      py::vectorize([](double mu, double beta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gumbel_rng(mu, beta, r, &std::cout);
      }),
      "rng for gumbel distribution.");

    m.def("lognormal_lpdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_lognormal_lpdf(y, mu, sigma, &std::cout);
      }),
      "lpdf for lognormal distribution.");

    m.def("lognormal_cdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_lognormal_cdf(y, mu, sigma, &std::cout);
      }),
      "cdf for lognormal distribution.");

    m.def("lognormal_lcdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_lognormal_lcdf(y, mu, sigma, &std::cout);
      }),
      "lcdf for lognormal distribution.");

    m.def("lognormal_lccdf",
      py::vectorize([](double y, double mu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_lognormal_lccdf(y, mu, sigma, &std::cout);
      }),
      "lccdf for lognormal distribution.");

    m.def("lognormal_rng",
      py::vectorize([](double mu, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_lognormal_rng(mu, sigma, r, &std::cout);
      }),
      "rng for lognormal distribution.");

    m.def("chi_square_lpdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_chi_square_lpdf(y, nu, &std::cout);
      }),
      "lpdf for chi_square distribution.");

    m.def("chi_square_cdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_chi_square_cdf(y, nu, &std::cout);
      }),
      "cdf for chi_square distribution.");

    m.def("chi_square_lcdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_chi_square_lcdf(y, nu, &std::cout);
      }),
      "lcdf for chi_square distribution.");

    m.def("chi_square_lccdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_chi_square_lccdf(y, nu, &std::cout);
      }),
      "lccdf for chi_square distribution.");

    m.def("chi_square_rng",
      py::vectorize([](double nu, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_chi_square_rng(nu, r, &std::cout);
      }),
      "rng for chi_square distribution.");

    m.def("inv_chi_square_lpdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_chi_square_lpdf(y, nu, &std::cout);
      }),
      "lpdf for inv_chi_square distribution.");

    m.def("inv_chi_square_cdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_chi_square_cdf(y, nu, &std::cout);
      }),
      "cdf for inv_chi_square distribution.");

    m.def("inv_chi_square_lcdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_chi_square_lcdf(y, nu, &std::cout);
      }),
      "lcdf for inv_chi_square distribution.");

    m.def("inv_chi_square_lccdf",
      py::vectorize([](double y, double nu) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_chi_square_lccdf(y, nu, &std::cout);
      }),
      "lccdf for inv_chi_square distribution.");

    m.def("inv_chi_square_rng",
      py::vectorize([](double nu, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_chi_square_rng(nu, r, &std::cout);
      }),
      "rng for inv_chi_square distribution.");

    m.def("scaled_inv_chi_square_lpdf",
      py::vectorize([](double y, double nu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_scaled_inv_chi_square_lpdf(y, nu, sigma, &std::cout);
      }),
      "lpdf for scaled_inv_chi_square distribution.");

    m.def("scaled_inv_chi_square_cdf",
      py::vectorize([](double y, double nu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_scaled_inv_chi_square_cdf(y, nu, sigma, &std::cout);
      }),
      "cdf for scaled_inv_chi_square distribution.");

    m.def("scaled_inv_chi_square_lcdf",
      py::vectorize([](double y, double nu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_scaled_inv_chi_square_lcdf(y, nu, sigma, &std::cout);
      }),
      "lcdf for scaled_inv_chi_square distribution.");

    m.def("scaled_inv_chi_square_lccdf",
      py::vectorize([](double y, double nu, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_scaled_inv_chi_square_lccdf(y, nu, sigma, &std::cout);
      }),
      "lccdf for scaled_inv_chi_square distribution.");

    m.def("scaled_inv_chi_square_rng",
      py::vectorize([](double nu, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_scaled_inv_chi_square_rng(nu, sigma, r, &std::cout);
      }),
      "rng for scaled_inv_chi_square distribution.");

    m.def("exponential_lpdf",
      py::vectorize([](double y, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exponential_lpdf(y, beta, &std::cout);
      }),
      "lpdf for exponential distribution.");

    m.def("exponential_cdf",
      py::vectorize([](double y, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exponential_cdf(y, beta, &std::cout);
      }),
      "cdf for exponential distribution.");

    m.def("exponential_lcdf",
      py::vectorize([](double y, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exponential_lcdf(y, beta, &std::cout);
      }),
      "lcdf for exponential distribution.");

    m.def("exponential_lccdf",
      py::vectorize([](double y, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exponential_lccdf(y, beta, &std::cout);
      }),
      "lccdf for exponential distribution.");

    m.def("exponential_rng",
      py::vectorize([](double beta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_exponential_rng(beta, r, &std::cout);
      }),
      "rng for exponential distribution.");

    m.def("gamma_lpdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gamma_lpdf(y, alpha, beta, &std::cout);
      }),
      "lpdf for gamma distribution.");

    m.def("gamma_cdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gamma_cdf(y, alpha, beta, &std::cout);
      }),
      "cdf for gamma distribution.");

    m.def("gamma_lcdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gamma_lcdf(y, alpha, beta, &std::cout);
      }),
      "lcdf for gamma distribution.");

    m.def("gamma_lccdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gamma_lccdf(y, alpha, beta, &std::cout);
      }),
      "lccdf for gamma distribution.");

    m.def("gamma_rng",
      py::vectorize([](double alpha, double beta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_gamma_rng(alpha, beta, r, &std::cout);
      }),
      "rng for gamma distribution.");

    m.def("inv_gamma_lpdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_gamma_lpdf(y, alpha, beta, &std::cout);
      }),
      "lpdf for inv_gamma distribution.");

    m.def("inv_gamma_cdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_gamma_cdf(y, alpha, beta, &std::cout);
      }),
      "cdf for inv_gamma distribution.");

    m.def("inv_gamma_lcdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_gamma_lcdf(y, alpha, beta, &std::cout);
      }),
      "lcdf for inv_gamma distribution.");

    m.def("inv_gamma_lccdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_gamma_lccdf(y, alpha, beta, &std::cout);
      }),
      "lccdf for inv_gamma distribution.");

    m.def("inv_gamma_rng",
      py::vectorize([](double alpha, double beta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_inv_gamma_rng(alpha, beta, r, &std::cout);
      }),
      "rng for inv_gamma distribution.");

    m.def("weibull_lpdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_weibull_lpdf(y, alpha, sigma, &std::cout);
      }),
      "lpdf for weibull distribution.");

    m.def("weibull_cdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_weibull_cdf(y, alpha, sigma, &std::cout);
      }),
      "cdf for weibull distribution.");

    m.def("weibull_lcdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_weibull_lcdf(y, alpha, sigma, &std::cout);
      }),
      "lcdf for weibull distribution.");

    m.def("weibull_lccdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_weibull_lccdf(y, alpha, sigma, &std::cout);
      }),
      "lccdf for weibull distribution.");

    m.def("weibull_rng",
      py::vectorize([](double alpha, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_weibull_rng(alpha, sigma, r, &std::cout);
      }),
      "rng for weibull distribution.");

    m.def("frechet_lpdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_frechet_lpdf(y, alpha, sigma, &std::cout);
      }),
      "lpdf for frechet distribution.");

    m.def("frechet_cdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_frechet_cdf(y, alpha, sigma, &std::cout);
      }),
      "cdf for frechet distribution.");

    m.def("frechet_lcdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_frechet_lcdf(y, alpha, sigma, &std::cout);
      }),
      "lcdf for frechet distribution.");

    m.def("frechet_lccdf",
      py::vectorize([](double y, double alpha, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_frechet_lccdf(y, alpha, sigma, &std::cout);
      }),
      "lccdf for frechet distribution.");

    m.def("frechet_rng",
      py::vectorize([](double alpha, double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_frechet_rng(alpha, sigma, r, &std::cout);
      }),
      "rng for frechet distribution.");

    m.def("rayleigh_lpdf",
      py::vectorize([](double y, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_rayleigh_lpdf(y, sigma, &std::cout);
      }),
      "lpdf for rayleigh distribution.");

    m.def("rayleigh_cdf",
      py::vectorize([](double y, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_rayleigh_cdf(y, sigma, &std::cout);
      }),
      "cdf for rayleigh distribution.");

    m.def("rayleigh_lcdf",
      py::vectorize([](double y, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_rayleigh_lcdf(y, sigma, &std::cout);
      }),
      "lcdf for rayleigh distribution.");

    m.def("rayleigh_lccdf",
      py::vectorize([](double y, double sigma) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_rayleigh_lccdf(y, sigma, &std::cout);
      }),
      "lccdf for rayleigh distribution.");

    m.def("rayleigh_rng",
      py::vectorize([](double sigma, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_rayleigh_rng(sigma, r, &std::cout);
      }),
      "rng for rayleigh distribution.");

    m.def("wiener_lpdf",
      py::vectorize([](double y, double alpha, double tau, double beta, double delta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_wiener_lpdf(y, alpha, tau, beta, delta, &std::cout);
      }),
      "lpdf for wiener distribution.");

    m.def("pareto_lpdf",
      py::vectorize([](double y, double y_min, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_lpdf(y, y_min, alpha, &std::cout);
      }),
      "lpdf for pareto distribution.");

    m.def("pareto_cdf",
      py::vectorize([](double y, double y_min, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_cdf(y, y_min, alpha, &std::cout);
      }),
      "cdf for pareto distribution.");

    m.def("pareto_lcdf",
      py::vectorize([](double y, double y_min, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_lcdf(y, y_min, alpha, &std::cout);
      }),
      "lcdf for pareto distribution.");

    m.def("pareto_lccdf",
      py::vectorize([](double y, double y_min, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_lccdf(y, y_min, alpha, &std::cout);
      }),
      "lccdf for pareto distribution.");

    m.def("pareto_rng",
      py::vectorize([](double y_min, double alpha, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_rng(y_min, alpha, r, &std::cout);
      }),
      "rng for pareto distribution.");

    m.def("pareto_type_2_lpdf",
      py::vectorize([](double y, double mu, double lambda, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_type_2_lpdf(y, mu, lambda, alpha, &std::cout);
      }),
      "lpdf for pareto_type_2 distribution.");

    m.def("pareto_type_2_cdf",
      py::vectorize([](double y, double mu, double lambda, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_type_2_cdf(y, mu, lambda, alpha, &std::cout);
      }),
      "cdf for pareto_type_2 distribution.");

    m.def("pareto_type_2_lcdf",
      py::vectorize([](double y, double mu, double lambda, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_type_2_lcdf(y, mu, lambda, alpha, &std::cout);
      }),
      "lcdf for pareto_type_2 distribution.");

    m.def("pareto_type_2_lccdf",
      py::vectorize([](double y, double mu, double lambda, double alpha) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_type_2_lccdf(y, mu, lambda, alpha, &std::cout);
      }),
      "lccdf for pareto_type_2 distribution.");

    m.def("pareto_type_2_rng",
      py::vectorize([](double mu, double lambda, double alpha, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_pareto_type_2_rng(mu, lambda, alpha, r, &std::cout);
      }),
      "rng for pareto_type_2 distribution.");

    m.def("beta_lpdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_beta_lpdf(y, alpha, beta, &std::cout);
      }),
      "lpdf for beta distribution.");

    m.def("beta_cdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_beta_cdf(y, alpha, beta, &std::cout);
      }),
      "cdf for beta distribution.");

    m.def("beta_lcdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_beta_lcdf(y, alpha, beta, &std::cout);
      }),
      "lcdf for beta distribution.");

    m.def("beta_lccdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_beta_lccdf(y, alpha, beta, &std::cout);
      }),
      "lccdf for beta distribution.");

    m.def("beta_rng",
      py::vectorize([](double alpha, double beta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_beta_rng(alpha, beta, r, &std::cout);
      }),
      "rng for beta distribution.");

    m.def("von_mises_lpdf",
      py::vectorize([](double y, double mu, double kappa) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_von_mises_lpdf(y, mu, kappa, &std::cout);
      }),
      "lpdf for von_mises distribution.");

    m.def("von_mises_rng",
      py::vectorize([](double mu, double kappa, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_von_mises_rng(mu, kappa, r, &std::cout);
      }),
      "rng for von_mises distribution.");

    m.def("uniform_lpdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_uniform_lpdf(y, alpha, beta, &std::cout);
      }),
      "lpdf for uniform distribution.");

    m.def("uniform_cdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_uniform_cdf(y, alpha, beta, &std::cout);
      }),
      "cdf for uniform distribution.");

    m.def("uniform_lcdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_uniform_lcdf(y, alpha, beta, &std::cout);
      }),
      "lcdf for uniform distribution.");

    m.def("uniform_lccdf",
      py::vectorize([](double y, double alpha, double beta) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_uniform_lccdf(y, alpha, beta, &std::cout);
      }),
      "lccdf for uniform distribution.");

    m.def("uniform_rng",
      py::vectorize([](double alpha, double beta, boost::ecuyer1988 & r) {
        py::scoped_ostream_redirect stream(
            std::cout,                               // std::ostream&
            py::module::import("sys").attr("stdout") // Python output
        );
        return allcall_functions::call_uniform_rng(alpha, beta, r, &std::cout);
      }),
      "rng for uniform distribution.");
