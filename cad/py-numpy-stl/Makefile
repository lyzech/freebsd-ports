PORTNAME=	numpy-stl
DISTVERSION=	2.10.1
DISTVERSIONPREFIX=	v
CATEGORIES=	cad python
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

COMMENT=	Simple library to make working with STL files fast and easy

USE_GITHUB=	yes
GH_ACCOUNT=	WoLpH

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
