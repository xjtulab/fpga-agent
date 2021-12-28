# fpga-agent

### Build and Run

#### Using CMake

**Requires** 

- `oatpp` and `oatpp-consul` modules installed. You may run `utility/install-oatpp-modules.sh` 
script to install required oatpp modules.

```
$ mkdir build && cd build
$ cmake ..
$ make 
$ ./example-consul-exe          # - run application.
```

#### In Docker

```
$ docker build -t example-consul .
$ docker run -p 8000:8000 -t example-consul
