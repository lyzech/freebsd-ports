# $FreeBSD$

PORTNAME=	cura
PORTVERSION=	4.4.0
CATEGORIES=	cad
DISTVERSIONPREFIX=	v

COMMENT=	C++ implementation of 3mf loading

USE_GITHUB=	yes
GH_ACCOUNT=	${CURA_GH_ACCOUNT}
GH_PROJECT=	Cura

GH_TUPLE=	Ultimaker:Uranium:${CURAVERSION}:uranium

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uranium>0:devel/py-uranium@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}savitar>0:cad/py-savitar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${LOCALBASE}/bin/CuraEngine:cad/curaengine

USES=		cmake gettext python:3.4+ qt:5 shebangfix
USE_PYTHON=	flavors
USE_QT=		graphicaleffects

SHEBANG_FILES=	cura_app.py

CMAKE_ARGS=	-DURANIUM_DIR=${WRKSRC_uranium} \
		-DCURA_VERSION=${version} \
		-DCURA_SDK_VERSION=6.0.0 \
		-DCURA_CLOUD_API_VERSION=1
#		-DCURA_BINARY_DATA_DIRECTORY=${WRKSRC_curabinarydata} \

.include "${.CURDIR:H:H}/cad/cura/Makefile.common"

.include <bsd.port.mk>
