# MAYBE XANEL2

this protype maybe will be xanel2 but who knows?

## BUILD

- setup the build folder usign `setup_build.sh` or do it manually

__usign setup_build.sh:__

```sh
./setup_build.sh
# or use clean to cleanup the build folder
./setup_build.sh clean
```

__manual:__

```sh
mkdir build
cd build
cmake ..
```

- actual build (if setup_build.sh is used then it use ninja)

```sh
# if you use make
make -j${nproc}
# ninja if you specify using ninja
ninja -C build
```
