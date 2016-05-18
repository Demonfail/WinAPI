#include "Error.h"

const char* ErrorGetString(ErrorCode err) {
	switch (err) {
	case ErrorCode::ERR_OK:       return "No Error.";
	case ErrorCode::ERR_FAIL:     return "Something went wrong.";
	case ErrorCode::ERR_LOAD:     return "Failed to load resource.";
	case ErrorCode::ERR_REGISTER: return "Failed to register component.";
	case ErrorCode::ERR_CREATE:   return "Failed to create component.";
	case ErrorCode::ERR_HOOK:     return "Failed to hook component.";
	case ErrorCode::ERR_SET:      return "Failed to set component.";
	default:                      return "Undefined Error.";
	}
	return "";
}

double ErrorHandle(ErrorCode err) {
	if (err == ErrorCode::ERR_OK) {
		return 1;
	}

	std::cout << ErrorGetString(err);
	MessageBox(NULL, TEXT(ErrorGetString(err)), "Error!", MB_ICONSTOP);
	return 0;
}