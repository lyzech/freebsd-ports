# $FreeBSD$

PORTNAME=	cq-editor
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	CadQuery GUI editor based on PyQT

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cadquery:cad/py-cadquery@${PY_FLAVOR}

USES=		pyqt:5 python:3.6+
USE_PYTHON=	autoplist distutils
USE_PYQT=	core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	CadQuery
GH_PROJECT=	CQ-editor

.include <bsd.port.mk>
