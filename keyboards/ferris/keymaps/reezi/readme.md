# hardware

count | part | from
------|------|-----
20x | keycap choc MBK pastel yellow | splitkb
20x | keycap choc MBK pastel green | splitkb
36x | switch kailh choc pink 20cN | splitkb
50x | hotswap socket kailh choc | splitkb
2x | Elite-C rev4 | splitkb
2x | mill max low profile socket | splitkb
2x | TRRS jack TH plug | splitkb
2x | TRRS jack TH 90° adapter | splitkb
1x | TRRS jack braided cable | splitkb
1x | PCB left+right halves | jlcpcb
1x | usb-c usb-c cable | amazon
1x | usb-c usb-a adapter | amazon
10x | rubber feet | amazon

# soldering gear

part | from
-----|-----
soldering iron+kit | amazon
soldering mat | amazon
solder 0.3mm no lead | amazon
solder 0.6mm no lead | amazon

# firmware

```sh
qmk compile
ls ~/keeb/qmkfw/.build

# from root of qmk repo
make ferris/sweep:reezi:dfu-split-left
make ferris/sweep:reezi:dfu-split-right

qmk flash
```
