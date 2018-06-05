@echo off

set cmd=%1
if "%cmd%" == "" set cmd="test" 

set here=%CD:\=/%
set here=/%here::=%

if "%cmd%" == "run" (
	docker run --rm -v %here%:/opt/pycmdstan pycmdstan %2 %3 %4 %5 %6 %7 %8 %9
) else if "%cmd%" == "runit" (
	docker run --rm -it -v %here%:/opt/pycmdstan pycmdstan %2 %3 %4 %5 %6 %7 %8 %9
) else if "%cmd%" == "test" (
	make run pytest --cov=pycmdstan -n 8 pycmdstan/tests.py
) else if "%cmd%" == "build" (
	docker build -t pycmdstan .
) else if "%cmd%" == "pkg" (
	make run python setup.py sdist bdist_wheel
) else if "%cmd%" == "pypi" (
	make pkg
	make runit twine upload dist/*
) else (
	make test
)
exit /b


:usage
echo usage:
echo make run ...
echo make runit ...
echo make test
echo make build
echo make pkg
exit /b