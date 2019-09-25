import ctypes

def EODrive(dll):
	#EO_API int EO_GetHandleBySerial(short serial);
	dll.EO_GetHandleBySerial.argtypes = [ctypes.c_short]
	dll.EO_GetHandleBySerial.restype = ctypes.c_int
	#EO_API int EO_InitHandle();
	dll.EO_InitHandle.argtypes = None
	dll.EO_InitHandle.restype = ctypes.c_int
	#EO_API int EO_InitAllHandles();
	dll.EO_InitAllHandles.argtypes = None
	dll.EO_InitAllHandles.restype = ctypes.c_int
	#EO_API int EO_GetAllHandles(int *handles, int size);
	dll.EO_GetAllHandles.argtypes = [ctypes.c_int]
	dll.EO_GetAllHandles.restype = ctypes.c_int
	#EO_API int EO_NumberOfCurrentHandles();
	dll.EO_NumberOfCurrentHandles.argtypes = None
	dll.EO_NumberOfCurrentHandles.restype = ctypes.c_int
	#EO_API void EO_ReleaseHandle(int handle);
	dll.EO_ReleaseHandle.argtypes = [ctypes.c_int]
	dll.EO_ReleaseHandle.restype = None
	#EO_API void EO_ReleaseAllHandles();
	dll.EO_ReleaseAllHandles.argtypes = None
	dll.EO_ReleaseAllHandles.restype = None
	#EO_API int EO_Move(int handle, double position);
	dll.EO_Move.argtypes = [ctypes.c_double]
	dll.EO_Move.restype = ctypes.c_int
	#EO_API int EO_GetMaxCommand(int handle, double *maxCommand);
	dll.EO_GetMaxCommand.argtypes = [ctypes.POINTER(ctypes.c_double)]
	dll.EO_GetMaxCommand.restype = ctypes.c_int
	#EO_API int EO_GetCommandPosition(int handle, double *position);
	dll.EO_GetCommandPosition.argtypes = [ctypes.POINTER(ctypes.c_double)]
	dll.EO_GetCommandPosition.restype = ctypes.c_int
	#EO_API int EO_GetSerialNumber(int handle, int *serial);
	dll.EO_GetSerialNumber.argtypes = [ctypes.POINTER(ctypes.c_int)]
	dll.EO_GetSerialNumber.restype = ctypes.c_int
