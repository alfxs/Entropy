#include <sys/random.h>

#include <errno.h>

#include "Entropy.h"

int GetEntropy (void* buffer, size_t length) {
	// Length Check
	if (length > 256) { // Too many bytes requested
		return ENTROPY_EIO;
	}
	void* end = buffer + length;
	while (buffer < end) {
		// System Call
		ssize_t nbytes = getrandom (buffer, end - buffer, 0);
		if (nbytes <= 0) {
			switch (errno) {
				case EINTR:
					continue;
				case EFAULT:
					return ENTROPY_EFAULT;
				default:
					return ENTROPY_EIO;
			}
		}
		buffer += nbytes;
	}
	// Exit Success
	return 0;
}
