#ifndef _unistd_H_
#define _unistd_H_

#define POSIX_FADV_SEQUENTIAL    2 /* Expect sequential page references.    */
#define POSIX_FADV_DONTNEED    4 /* Don't need these pages.        */

#define fdatasync(fd) 0
#define posix_fadvise(fd, offset, len, advice) 0

#define  STDOUT_FILENO 1

#define __typeof__ decltype

typedef signed long ssize_t;

#define S_IRUSR _S_IREAD
#define S_IWUSR _S_IWRITE

#endif //_unistd_H_