# Entropy
A small, cross-platform interface to collect entropy from the operating system.

## Synopsis
\#include <Entropy.h>

int GetEntropy \(void\* buffer, size\_t length\);

## Description
GetEntropy\(\) fills a buffer with system-provided entropy, which can be used as input for process-context pseudorandom generators. The maximum buffer size 
permitted is 256 bytes.

Entropy is primarily intended for use in the construction and seeding of user-space pseudorandom generators. Clients who simply require random data should use 
the [Random](https://github.com/alfxs/Random) interface instead.

## Return Values
Upon successful completion, the value 0 is returned; otherwise one of the following predefined macros are returned to indicate the error.

### Error Codes

\[ENTROPY\_EFAULT\] The *buffer* parameter points to an invalid address.

\[ENTROPY\_EIO\] Either too many bytes were requested or some other fatal error occurred.

## Supported Operating Systems
- FreeBSD 12.0+ [getentropy\(3\)](man/FreeBSD/getentropy.3 "FreeBSD GETENTROPY\(3\)")
- Linux 3.17+ [getrandom\(2\)](man/Linux/getrandom.2 "Linux GETRANDOM\(2\)")
- MacOS 10.12+ [getentropy\(2\)](man/MacOS/getentropy.2 "MacOS GETENTROPY\(2\)")
- OpenBSD 5.6+ [getentropy\(2\)](man/OpenBSD/getentropy.2 "OpenBSD GETENTROPY\(2\)")
