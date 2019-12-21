# $FreeBSD$

PORTNAME=	dmenu-wayland
PORTVERSION=	0.1
CATEGORIES=	x11

COMMENT=	dmenu for wayland-compositors

USE_GITHUB=	yes
GH_ACCOUNT=	nyyManni
GH_PROJECT=	dmenu-wayland
GH_TAGNAME=	v${PORTVERSION}

USES=		meson ninja pkgconfig
USE_GNOME=	cairo pango

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon


.include <bsd.port.mk>
