# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	scrot
DISTVERSION=	1.1.1
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SCReenshOT - command line screen capture utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libgiblib.so:graphics/giblib \
		libImlib2.so:graphics/imlib2

USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects

USE_HARDENING=	cfi safestack

USES=		autoreconf
GNU_CONFIGURE=	yes
USE_XORG=	x11 xfixes xcursor

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS CONTRIBUTING.md ChangeLog README

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
