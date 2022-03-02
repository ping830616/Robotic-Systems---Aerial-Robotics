MODEL = 'bh_f14';
open_system(MODEL)

open_system([MODEL,'/Plant'],'tab')
open_system([MODEL,'/Wind'],'tab')
open_system([MODEL,'/Controller'],'tab')

slbuild(MODEL)