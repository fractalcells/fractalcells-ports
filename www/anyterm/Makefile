# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	anyterm
PORTVERSION=	1.1.29
PORTREVISION=	20
CATEGORIES=	www
MASTER_SITES=	http://anyterm.org/download/ \
		http://dl1.douglasthrift.net/${PORTNAME}/ \
		http://dl2.douglasthrift.net/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Terminal emulator on a Web page

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

BROKEN_aarch64=		does not build: libstdc++.so: undefined reference to __floatunditf@GCC_4.2.0
BROKEN_armv6=		does not build: libstdc++.so: undefined reference to __aeabi_idiv@GCC_3.5
BROKEN_armv7=		does not build: libstdc++.so: undefined reference to __aeabi_idiv@GCC_3.5
BROKEN_powerpc64=	Does not build: ld: cannot find -lboost_system

USE_RC_SUBR=	anytermd
USES=		gmake iconv localbase tar:tbz2
USE_GCC=	any
ALL_TARGET=	default_target
PLIST_FILES=	man/man1/anytermd.1.gz \
		sbin/anytermd

# Force the use of an older C++ standard; anyterm 1.1.29 is not compatible with
# C++11.
USE_CXXSTD=	gnu++98

post-patch:
	@${REINPLACE_CMD} -e 's|/private/etc/apache2|${FILESDIR}|' \
		${WRKSRC}/scripts/mimetype.sh
	@${REINPLACE_CMD} \
		-e 's|$$(CPP_FLAGS)|& ${CPPFLAGS} |' \
		-e '/^COMPILE_FLAGS=/s|$$| ${CXXFLAGS}|' \
		-e 's|$${OPTIMISE_FLAGS}||' \
		-e 's|$$(LINK_FLAGS)|& -L${ICONV_PREFIX}/lib ${ICONV_LIB} |' \
		${WRKSRC}/common.mk
	@${REINPLACE_CMD} \
		-e '/^COMPILE_FLAGS=/s|$$| ${CXXFLAGS}|' \
		-e 's|$$(INC_FLAGS)|& ${CPPFLAGS} |' \
		-e 's|$$(CXXFLAGS)||' -e 's|$$(OPTIMISE_FLAGS)||' \
		${WRKSRC}/libpbe/common.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/anytermd ${STAGEDIR}${PREFIX}/sbin/anytermd
	${INSTALL_MAN} ${WRKSRC}/anytermd.1 ${STAGEDIR}${MANPREFIX}/man/man1/anytermd.1

.include <bsd.port.mk>
