# HandmadeQuakeP
Portable version of the HandmadeQuake project.

Differences from HandmadeQuake
  • In VS project settings add "/subsystem:windows /ENTRY:mainCRTStartup" to command line options for the linker to support standard 
  main(). Currently argc and argv are passed in from the system unlike WinMain. This means they are not globals and have to be passed
  with each function that uses them.
