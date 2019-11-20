# $FreeBSD$

PORTNAME=	uranium
PORTVERSION=	${CURAVERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for libarcus

USE_GITHUB=	yes
GH_ACCOUNT=	${CURA_GH_ACCOUNT}
GH_PROJECT=	Uranium

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arcus>0:devel/py-arcus@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arcus>0:devel/py-arcus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy-stl>0:cad/py-numpy-stl@${PY_FLAVOR} \
		${PYQT_PY_RELNAME}-quick>0:x11-toolkits/py-qt5-quick@${PY_FLAVOR}
		
		
USES=		cmake gettext python:3.4+ pyqt:5 #qt:5
USE_PYQT=	core gui opengl qml svg
#USE_QT=		quickcontrols quickcontrols2
USE_PYTHON=	flavors

INSTALL_TARGET=	install

.include "${.CURDIR:H:H}/cad/cura/Makefile.common"

.include <bsd.port.mk>
