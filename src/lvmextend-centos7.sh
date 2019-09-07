#!/usr/bin/env bash

sudo lvs
sudo lvextend -l +100%FREE /dev/cl_boronvcent/root
sudo xfs_growfs /dev/cl_boronvcent/root 
df -h
