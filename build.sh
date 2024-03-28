BINARY_NAME="arcade"

if [ "$1" = "--help" ] ||  [ "$1" = "-h" ]; then
  echo "Usage: ./build.sh [debug|ninja] [re]"
  echo "ninja: build using ninja"
  echo "debug: build in debug mode"
  echo "re: remove build directory and rebuild"
  exit 0
fi

if [ "$1" = "re" ]; then
  rm -rf build
  rm -rf cmake-build-debug
fi

if [ "$2" = "re"  ]; then
  rm -rf build
  rm -rf cmake-build-debug
fi


if [ "$1" = "debug" ]; then
  echo "Debug mode"
  rm -rf build
  rm -rf cmake-build-debug
  mkdir -p build && cd build && cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug && cmake --build . && cd ..
  exit 0
fi

if [ "$1" = "ninja" ]; then
  echo "Ninja mode"
  rm -rf build
  rm -rf cmake-build-debug

  if [ "$2" = "debug" ]; then
    mkdir -p build && cd build && cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Debug && ninja && cd ..
    exit 0
  fi
  mkdir -p build && cd build && cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Release && ninja && cd ..
  exit 0
fi

if [ "$1" = "clean" ] || [ "$1" = "c" ]; then
  rm -rf build
  rm -rf lib
  rm $BINARY_NAME
  exit 0
fi

mkdir -p build && cd build && cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build . && cd ..
