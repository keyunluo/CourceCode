#-*- coding:utf-8 -*-
#
import sys
from cx_Freeze import setup, Executable

base = None

options = {
    'build_exe': {
        'includes': 'atexit'
    }
}

executables = [
    Executable('SiteTableScraper.py', base=base,icon="py.ico")
]

setup(name='骆克云',
      version='0.1',
      description='网页爬取',
      options=options,
      executables=executables
      )