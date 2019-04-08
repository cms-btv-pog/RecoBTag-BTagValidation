import os
import subprocess as sp

import ROOT

def check_root_file(file_name):

    if os.path.isfile(file_name):

      try:

        _f = ROOT.TFile.Open(file_name,'read')

        if (not _f) or _f.GetNkeys() == 0 or _f.TestBit(ROOT.TFile.kRecovered) or _f.IsZombie():
            
          sp.check_output(['rm', file_name])

        else:
          _f.Close()

      except Exception, e:
        sp.check_output(['rm', file_name])


if __name__ == '__main__':
  
  file_name = '<file_name>'

  check_root_file(file_name)
