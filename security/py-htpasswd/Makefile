# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	htpasswd
PORTVERSION=	2008.03.05
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for htpasswd

BROKEN=		unfetchable

USES=		python shebangfix tar:xz

PLIST_FILES=	bin/${PORTNAME}.py

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SHEBANG_FILES=	${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
