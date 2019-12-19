```
c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`
vs.
g++-9 -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`


On MacOS:
~/dev/pybind11-2.4.3/build/rwh_examples$ c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`
~/dev/pybind11-2.4.3/build/rwh_examples$ ls
Readme.rwh			example.cpp			example.cpython-36m-darwin.so*
~/dev/pybind11-2.4.3/build/rwh_examples$ python
Python 3.6.5 |Anaconda, Inc.| (default, Apr 26 2018, 08:42:37) 
[GCC 4.2.1 Compatible Clang 4.0.1 (tags/RELEASE_401/final)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> import example
>>> dir(example)
['__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'add']
>>> example.add(1,2)
3
```

