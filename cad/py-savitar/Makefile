# $FreeBSD$

PORTNAME=	savitar
PORTVERSION=	${CURAVERSION}
CATEGORIES=	cad devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Implementation of 3mf loading (python binding)

USE_GITHUB=	yes
GH_ACCOUNT=	${CURA_GH_ACCOUNT}
GH_PROJECT=	libSavitar

LIB_DEPENDS=	libSavitar.so:cad/savitar

USES=		cmake compiler:c++11-lang python:3.4+ pyqt:5
USE_PYQT=	sip
USE_PYTHON=	flavors

ALL_TARGET=	python_module_Savitar

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Savitar.so ${STAGEDIR}${PYTHON_SITELIBDIR}
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Savitar.so

.include "${.CURDIR:H:H}/cad/cura/Makefile.common"

.include <bsd.port.mk>
