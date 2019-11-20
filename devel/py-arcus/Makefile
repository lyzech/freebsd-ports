# $FreeBSD$

PORTNAME=	arcus
PORTVERSION=	${CURAVERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for libarcus

USE_GITHUB=	yes
GH_ACCOUNT=	${CURA_GH_ACCOUNT}
GH_PROJECT=	libArcus

LIB_DEPENDS=	libArcus.so:devel/arcus

USES=		cmake compiler:c++11-lang python:3.4+ pyqt:5
USE_PYQT=	sip
USE_PYTHON=	flavors
CMAKE_ON=	BUILD_PYTHON

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Arcus.so ${STAGEDIR}${PYTHON_SITELIBDIR}
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Arcus.so

.include "${.CURDIR:H:H}/cad/cura/Makefile.common"

.include <bsd.port.mk>
