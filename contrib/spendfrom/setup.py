from distutils.core import setup
setup(name='MUEspendfrom',
      version='1.0',
      description='Command-line utility for monetaryunit "coin control"',
      author='Gavin Andresen',
      author_email='gavin@monetaryunitfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
