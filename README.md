# C API Filesystem Plugins

> Inspired by [Modular Filesystems C API](https://github.com/tensorflow/community/pull/101)

## How it works

A plugin is a self-contained shared library (`.so` or `.dll`) with `C` symbols. With any programming language that supports calling `C` functions, we could use this plugin for reading/writing file, creating directories, etc.
