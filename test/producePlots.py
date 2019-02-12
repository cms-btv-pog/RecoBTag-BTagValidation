from RecoBTag.BTagValidation.BatchTool import *
from RecoBTag.BTagValidation.FileTool import *
from RecoBTag.BTagValidation.HistogramTool import *
from RecoBTag.BTagValidation.MergeTool import *
from RecoBTag.BTagValidation.MiscTool import *

import config

if __name__ == '__main__':

  # Choose which job you want to execute
  job = int(setup_job())

  # Initalize handlers for each step
  file_tool       = FileTool(config)
  histogram_tool  = HistogramTool(config)
  merge_tool      = MergeTool(config)

  if job == 1:
    file_tool.save_logical_file_names_all_samples_remotely()

  elif job == 2:
    file_tool.check_missing_files_all_samples_remotely()

  elif job == 3:
    file_tool.save_logical_file_names_all_samples_locally()

  elif job == 4:
    file_tool.copy_files_all_samples_locally()

  elif job == 5:
    file_tool.check_missing_files_all_samples_locally()

  elif job == 6:
    histogram_tool.make_and_send_jobs()

  elif job == 7:
    merge_tool.merge_histograms()

  elif job == 8:
    merge_tool.merge_datasets()

  else:
    pass
