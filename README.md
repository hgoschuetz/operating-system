# Operating system (myos)

A tiny operating system that can do (almost) nothing.  

## Note (to myself)

Build environment:  

    docker run --rm -it -v "$(pwd)":/root/env myos-buildenv

Build (in env.):  

    make build-x86

Emulate:

    qemu-system-x86_64 -cdrom dist/x86/kernel.iso
