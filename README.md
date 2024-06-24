# Steps to reproduce the bug at the bottom of this readme

```
homebrew install qt@5
```
Ideally, git clone `vcpkg` into `/opt` as well.

```
 ~/r/qt-vtk-example  lldb ./build/qtvtk_exe
(lldb) target create "./build/qtvtk_exe"
Current executable set to '/Users/jeffrey/repos/qt-vtk-example/build/qtvtk_exe' (arm64).
(lldb) run 
Process 41734 launched: '/Users/jeffrey/repos/qt-vtk-example/build/qtvtk_exe' (arm64)
2024-06-24 20:14:14.673535+1000 qtvtk_exe[41734:36059975] [miscellany] CLIENT ERROR: TUINSRemoteViewController does not override -viewServiceDidTerminateWithError: and thus cannot react to catastrophic errors beyond logging them
2024-06-24 20:14:17.058758+1000 qtvtk_exe[41734:36059975] [miscellany] CLIENT ERROR: TUINSRemoteViewController does not override -viewServiceDidTerminateWithError: and thus cannot react to catastrophic errors beyond logging them
2024-06-24 20:14:17.087349+1000 qtvtk_exe[41734:36059975] [miscellany] CLIENT ERROR: TUINSRemoteViewController does not override -viewServiceDidTerminateWithError: and thus cannot react to catastrophic errors beyond logging them
Process 41734 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x220)
    frame #0: 0x000000010002bbac qtvtk_exe`-[vtkCocoaGLView modifyDPIForBackingScaleFactorOfWindow:](self=0x000000012d6f5cf0, _cmd="modifyDPIForBackingScaleFactorOfWindow:", window=0x0000000000000000) at vtkCocoaGLView.mm:586:19
   583      // Ordinarily, DPI is hardcoded to 72, but in order for vtkTextActors
   584      // to have the correct apparent size, we adjust it per the NSWindow's
   585      // scaling factor.
-> 586      renderWindow->SetDPI(lround(72.0 * backingScaleFactor));
   587    }
   588  }
   589 
Target 0: (qtvtk_exe) stopped.
(lldb) exit
```