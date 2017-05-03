# $FreeBSD$

PORTNAME=	aucatsvc
PORTVERSION=	0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Web service for controlling sndiod volumes and playing notes

LICENSE=	ISCL

BUILD_DEPENDS=	kore-notls:devel/kore-notls \
		sassc:textproc/sassc
RUN_DEPENDS=	kore-notls:devel/kore-notls

USE_GITHUB=	yes
GH_ACCOUNT=	t6

MAKE_ARGS=	KORE=kore-notls

MODULE=		libexec/${PORTNAME}/${PORTNAME}-${PORTVERSION}.so
SUB_FILES=	${PORTNAME}.conf pkg-message
SUB_LIST=	MODULE=${LOCALBASE}/${MODULE} \
		USER=www CHROOT=${WWWDIR} \
		PORTNAME=${PORTNAME}
PLIST_SUB=	MODULE=${MODULE} PORTNAME=${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

post-patch:
	${TOUCH} ${WRKSRC}/conf/${PORTNAME}-${PORTVERSION}.conf

pre-build:
	@cd ${WRKSRC} && kore-notls flavor prod

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.so \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
