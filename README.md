# HandmadeQuakeP
Portable version of the HandmadeQuake project.

### Differences from HandmadeQuake
* In VS project settings add "/subsystem:windows /ENTRY:mainCRTStartup" to command line options for the linker to support standard main().Currently argc and argv are passed in from the system unlike WinMain.
* Uses i8, i16, i32 & u8, u16, u32 instead of int8, int16, int32 & uint8, uint16, uint32
