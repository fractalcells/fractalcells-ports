# Created by: ijliao
# $FreeBSD$

PORTNAME=	cvsps
DISTVERSION=	2.2b1
CATEGORIES=	devel
MASTER_SITES=	http://www.cobite.com/cvsps/
PKGNAMESUFFIX?=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create patchset information from CVS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		unfetchable
CONFLICTS=	cvsps-[0-9]*

USES=		gmake
ALL_TARGET=	cvsps

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
