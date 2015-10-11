#!/bin/bash
cmd=build/release/simplication
output_dir='./simplified'

mkdir -p $output_dir

for path in MeshsegBenchmark-1.0/data/off/*.off
do
  filename=$(basename "$path")
  output_path=$output_dir/$filename
  $cmd $path $output_path
done