#include "Resource.h"

ErrorCode Icon::Free() {
	delete m_hiIconSmall;
	delete m_hiIconBig;
	return ErrorCode::ERR_OK;
}

ErrorCode Icon::Load(string filename) {
	m_hiIconBig = (HICON)LoadImage(NULL, TEXT(filename), IMAGE_ICON, 64, 64, LR_LOADFROMFILE);
	if (m_hiIconBig == NULL) {
		return ErrorCode::ERR_LOAD;
	}
	m_hiIconSmall = (HICON)LoadImage(NULL, TEXT(filename), IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
	if (m_hiIconSmall == NULL) {
		return ErrorCode::ERR_LOAD;
	}
	return ErrorCode::ERR_OK;
}

HICON Icon::Get(IconType icon) {
	if (icon == IconType::IconSmall) {
		return m_hiIconSmall;
	}else
	if (icon == IconType::IconBig) {
		return m_hiIconBig;
	}
	return NULL;
}