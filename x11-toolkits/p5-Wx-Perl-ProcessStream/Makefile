# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Wx-Perl-ProcessStream
PORTVERSION=	0.32
PORTREVISION=	4
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to access IO of external processes via events

DEPRECATED=	Depends on expiring x11-toolkits/p5-Wx
EXPIRATION_DATE=	2019-09-04

BUILD_DEPENDS=	p5-Wx>=0.5000:x11-toolkits/p5-Wx
RUN_DEPENDS=	p5-Wx>=0.5000:x11-toolkits/p5-Wx

USE_WX=		3.0
WX_COMPS=	wx
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
