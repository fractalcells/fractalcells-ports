# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kubectl
PORTVERSION=	1.15.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes command-line tool

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

GO_PKGNAME=	k8s.io/kubernetes
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X k8s.io/kubernetes/pkg/kubectl/version.gitMajor=${PORTVERSION:R:R} \
		-X k8s.io/kubernetes/pkg/kubectl/version.gitMinor=${PORTVERSION:R:E} \
		-X k8s.io/kubernetes/pkg/kubectl/version.buildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X k8s.io/kubernetes/pkg/kubectl/version.gitCommit="" \
		-X k8s.io/kubernetes/pkg/kubectl/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
