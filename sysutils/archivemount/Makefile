# Created by: Evgeny Zhirnov <jirnov@gmail.com>
# $FreeBSD$

PORTNAME=	archivemount
DISTVERSION=	0.8.12
CATEGORIES=	sysutils
MASTER_SITES=	https://www.cybernoia.de/software/archivemount/

MAINTAINER=	jirnov@gmail.com
COMMENT=	Mount archives with FUSE

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse gmake iconv libarchive pkgconfig
GNU_CONFIGURE=	yes

USE_HARDENING=	pie:off relro:off

PLIST_FILES=	bin/archivemount \
		man/man1/archivemount.1.gz \
		sbin/mount_archive

SUB_FILES=	pkg-message

post-install:
		${RLN} ${STAGEDIR}${PREFIX}/bin/archivemount \
		    ${STAGEDIR}${PREFIX}/sbin/mount_archive

.include <bsd.port.mk>
