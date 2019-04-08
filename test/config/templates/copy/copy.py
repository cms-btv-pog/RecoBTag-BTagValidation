import subprocess as sp
import os

def copy(destination, source):
  """
  Just copy file.
  """

  make_directory(destination)

  _command = ['gfal-copy', '--force']
  _command.append('<protocol>' + source)
  _command.append('file:///' + destination)

  sp.call(_command)

def make_directory(directory):

  if not os.path.exists(directory):
    try:
      os.makedirs(directory)
    except OSError:
      if not os.path.isdir(directory):
        raise

  return directory

if __name__ == '__main__':
  
  destination = '<destination>'
  source      = '<source>'

  copy( destination, source)
