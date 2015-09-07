# mo-solver
A solver for multiple objective mixed linear programmes

## Dependencies
* CMake
* CppUnit

`apt-get install cmake libcppunit-dev`

## Installation
First, create a global directory:  
`mkdir multiobj`  
`cd multiobj`

Then, clone solver and utils:  
`git clone https://github.com/tvincent2/mo-utils.git`  
`git clone https://github.com/tvincent2/mo-solver.git`

Finally, build:  
`cd mo-solver`  
`mkdir build`  
`cd build`  
`cmake ..`  
`make`

And test!  
`test/mo_solver_tests`
