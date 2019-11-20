# $FreeBSD$

PORTNAME=	savitar
PORTVERSION=	${CURAVERSION}
CATEGORIES=	cad devel

COMMENT=	C++ implementation of 3mf loading

USE_GITHUB=	yes
GH_ACCOUNT=	${CURA_GH_ACCOUNT}
GH_PROJECT=	libSavitar

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lang

CMAKE_OFF=	BUILD_PYTHON

.include "${.CURDIR:H:H}/cad/cura/Makefile.common"

.include <bsd.port.mk>
