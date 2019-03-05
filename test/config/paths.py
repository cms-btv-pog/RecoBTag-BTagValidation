# main.py location, everything is defined with respect to it
main                = '/'.join(__file__.split('/')[:-2])
# If not really necessary don't change
samples             = '/'.join([ main, 'samples'])                                      # '/STORE/benjamin/17_08_BTV_2017_data/samples'                     #
logical_file_names  = '/'.join([ main, 'samples', 'logical_file_names'])                # '/STORE/benjamin/17_08_BTV_2017_data/samples/logical_file_names'  #
histograms          = '/'.join([ main, 'results', 'histograms'])
plots_final         = '/'.join([ main, 'results', 'plots_final'])
batch_results       = '/'.join([ main, 'results', 'batch'])
batch_templates     = '/'.join([ main, 'config', 'templates'])

# When you call voms-proxy-init --voms cms --valid 168:00
# As a result you get the output like /tmp/x509up_u78012
# Then copy this x509up_u78012 wherever you want and this is voms_user_proxy
proxy           = '/afs/cern.ch/user/a/algomez/x509up_u15148'
