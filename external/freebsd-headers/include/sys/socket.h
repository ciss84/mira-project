/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#ifndef _SYS_SOCKET_H_
#define	_SYS_SOCKET_H_

#include <sys/cdefs.h>
#include <sys/_types.h>
#include <sys/_iovec.h>
#include <machine/_align.h>
#include <sys/_types/_sa_family_t.h>
#include <sys/_types/_socklen_t.h>
#include <sys/_types/_ssize_t.h>
#include <sys/_sockaddr_storage.h>

#if defined(__cplusplus)
extern "C" {
#endif

/* socket types */
#define	SOCK_STREAM	1
#define	SOCK_DGRAM	2
#define	SOCK_RAW	3

/* socket options */
#define	SO_REUSEADDR	0x0004
#define	SO_KEEPALIVE	0x0008
#define	SO_BROADCAST	0x0020
#define	SO_LINGER	0x0080
#define	SO_REUSEPORT	0x0200

/* additional socket options */
#define	SO_SNDBUF	0x1001
#define	SO_RCVBUF	0x1002
#define	SO_SNDLOWAT	0x1003
#define	SO_RCVLOWAT	0x1004
#define	SO_SNDTIMEO	0x1005
#define	SO_RCVTIMEO	0x1006
#define	SO_ERROR	0x1007
#define	SO_TYPE		0x1008

struct linger {
	int	l_onoff;
	int	l_linger;
};

#define	SOL_SOCKET	0xffff

/* address families */
#define	AF_UNSPEC	0
#define	AF_LOCAL	AF_UNIX
#define	AF_UNIX		1
#define	AF_INET		2
#define	AF_INET6	28
#define	AF_MAX		38

#define	PF_UNSPEC	AF_UNSPEC
#define	PF_LOCAL	AF_LOCAL
#define	PF_UNIX		PF_LOCAL
#define	PF_INET		AF_INET
#define	PF_INET6	AF_INET6
#define	PF_MAX		AF_MAX

struct sockaddr {
	unsigned char	sa_len;
	sa_family_t	sa_family;
	char		sa_data[14];
};

struct msghdr {
	void		*msg_name;
	socklen_t	 msg_namelen;
	struct iovec	*msg_iov;
	int		 msg_iovlen;
	void		*msg_control;
	socklen_t	 msg_controllen;
	int		 msg_flags;
};

struct cmsghdr {
	socklen_t   cmsg_len;
	int     cmsg_level;
	int     cmsg_type;
};

#define	CMSG_DATA(cmsg)		((unsigned char *)(cmsg) + \
				 _ALIGN(sizeof(struct cmsghdr)))
#define	CMSG_NXTHDR(mhdr, cmsg)	\
	((char *)(cmsg) == NULL ? CMSG_FIRSTHDR(mhdr) : \
	    ((char *)(cmsg) + _ALIGN(((struct cmsghdr *)(cmsg))->cmsg_len) + \
	  _ALIGN(sizeof(struct cmsghdr)) > \
	    (char *)(mhdr)->msg_control + (mhdr)->msg_controllen) ? \
	    (struct cmsghdr *)0 : \
	    (struct cmsghdr *)(void *)((char *)(cmsg) + \
	    _ALIGN(((struct cmsghdr *)(cmsg))->cmsg_len)))
#define	CMSG_FIRSTHDR(mhdr) \
	((mhdr)->msg_controllen >= sizeof(struct cmsghdr) ? \
	 (struct cmsghdr *)(mhdr)->msg_control : \
	 (struct cmsghdr *)NULL)
#define	CMSG_SPACE(l)		(_ALIGN(sizeof(struct cmsghdr)) + _ALIGN(l))
#define	CMSG_LEN(l)		(_ALIGN(sizeof(struct cmsghdr)) + (l))

/* "Socket"-level control message types: */
#define	SCM_RIGHTS	0x01
#define	SCM_TIMESTAMP	0x02
#define	SCM_CREDS	0x03
#define	SCM_BINTIME	0x04


#define	MSG_PEEK	0x2
#define	MSG_DONTROUTE	0x4
#define	MSG_TRUNC	0x10
#define	MSG_CTRUNC	0x20
#define	MSG_WAITALL	0x40
#define	MSG_DONTWAIT	0x80
#define	MSG_NOSIGNAL	0x20000

#define	SHUT_RD		0
#define	SHUT_WR		1
#define	SHUT_RDWR	2

int	accept(int, struct sockaddr * __restrict, socklen_t * __restrict);
int	bind(int, const struct sockaddr *, socklen_t);
int	connect(int, const struct sockaddr *, socklen_t);
int	getpeername(int, struct sockaddr * __restrict, socklen_t * __restrict);
int	getsockname(int, struct sockaddr * __restrict, socklen_t * __restrict);
int	getsockopt(int, int, int, void * __restrict, socklen_t * __restrict);
int	listen(int, int);
ssize_t	recv(int, void *, size_t, int);
ssize_t	recvfrom(int, void *, size_t, int, struct sockaddr * __restrict, socklen_t * __restrict);
ssize_t	recvmsg(int, struct msghdr *, int);
ssize_t	send(int, const void *, size_t, int);
ssize_t	sendto(int, const void *,
	    size_t, int, const struct sockaddr *, socklen_t);
ssize_t	sendmsg(int, const struct msghdr *, int);
int	setsockopt(int, int, int, const void *, socklen_t);
int	shutdown(int, int);
int	socket(int, int, int);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SOCKET_H_ */

