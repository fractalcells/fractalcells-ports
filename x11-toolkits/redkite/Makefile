# $FreeBSD$

PORTNAME=	redkite
DISTVERSIONPREFIX=	v
DISTVERSION=	v0.6-4
DISTVERSIONSUFFIX=	-gad49c91
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI toolkit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang gnome localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	quamplex
USE_GNOME=	cairo
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR=${PREFIX}/lib
CMAKE_OFF=	ENABLE_EXAMPLES

.include <bsd.port.mk>
