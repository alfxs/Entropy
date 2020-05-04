#include <sys/random.h>

#include <errno.h>

#include "Entropy.h"

int GetEntropy (void* buffer, size_t length) {
	// System Call
	int code = getentropy (buffer, length);
	// Exit Success
	if (code == 0) {
		return 0;
	}
	// Exit Failure
	if (errno == EINVAL) {
		return ENTROPY_EFAULT;
	}
	return ENTROPY_EIO;
}
