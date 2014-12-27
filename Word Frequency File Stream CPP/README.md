Assignment
This program  is able to read in a text file and output the frequency of each work in the file. The 'experts' will use this data to analyze and compare the writing of Shakespeare to modern day poets and play writes.

The input files are likely to have punctuation at the end of some words. Those punctuation marks should be discarded so that the following two inputs would be considered equivalent: hello and hello,. In addition, I have ignored quotes, such that 'hello' and hello are equivalent. The following punctuation at the end of a word have been deleted:
•	!
•	.
•	,
•	?
•	;
•	:
•	-
•	|
And the following punctuation AROUND words have been deleted:
•	'
Return Values, Errors and Error Handling
My program checks to see that a single filename is specified on the command line. If it is not, the program prints out the following error to STDERR:
   Usage:

      main filename
   
'main' is the name of the executable is determined dynamically. Thus, if the name of the executable was changed to 'count', the help would be:
   Usage:

      count filename
   
If the file specified by the user cannot be opened, the program prints the following error message to STDERR:
   count: nofile: No such file
   
Again, 'count' is the name of the executable determined dynamically, and 'nofile' is the name of the file the user specified. The program has an exit code of '2' in this scenario.
If the program successfully runs, it sets the exit code to '0'.
Input File
Given a file with the following data (lorem.txt):
   Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ante tortor,
   sollicitudin a laoreet sed, convallis sed mi. In volutpat sollicitudin
   felis, quis pharetra nibh aliquet id. Fusce vel sapien non nisi blandit
   sollicitudin nec sed dolor. Mauris commodo, eros et tincidunt imperdiet,
   leo metus dapibus justo, vel placerat urna risus sed nibh. Duis sed metus
   sit amet mauris tempor lacinia. Duis eu dolor ipsum, ac tincidunt quam.
   Pellentesque vestibulum vehicula congue. Pellentesque commodo orci id ante
   gravida et auctor ligula volutpat. Cras mattis felis sit amet mi gravida
   tempor vulputate tellus venenatis. Proin tempus urna sed lacus ullamcorper
   malesuada. Pellentesque ac ligula diam. Pellentesque eu est lorem. Donec
   arcu nunc, fringilla sit amet vulputate vitae, feugiat at tellus. Nam
   tincidunt dictum magna ac adipiscing.

   Duis diam purus, imperdiet in auctor quis, ultrices eget odio. Cras
   pellentesque elit tristique velit fringilla ornare. Ut blandit tellus
   neque, at facilisis felis. Duis tortor massa, fermentum non molestie in,
   suscipit non ipsum. Maecenas faucibus laoreet sapien, rutrum porta nunc
   malesuada at. Morbi placerat faucibus tortor eget gravida. Maecenas quis
   vestibulum massa. Phasellus a est urna, in imperdiet justo. Pellentesque
   viverra justo eu lacus ornare sed malesuada lacus ornare. Phasellus ornare
   elementum dui, sed pharetra risus placerat nec. Vivamus blandit sagittis
   magna, nec faucibus nunc convallis et. Nunc vel consectetur leo.
   Pellentesque non erat eget neque rutrum pellentesque. Nam eu libero leo.
   Pellentesque mattis, diam in placerat sollicitudin, dolor diam tristique
   nunc, quis accumsan sem turpis ac purus. Lorem ipsum dolor sit amet,
   consectetur. 
   
My program prints the following to STDOUT when run as main lorem.txt:
   Cras: 2
   Donec: 1
   Duis: 4
   Fusce: 1
   In: 1
   Lorem: 2
   Maecenas: 2
   Mauris: 1
   Morbi: 1
   Nam: 2
   Nunc: 1
   Pellentesque: 7
   Phasellus: 2
   Proin: 1
   Sed: 1
   Ut: 1
   Vivamus: 1
   a: 2
   ac: 4
   accumsan: 1
   adipiscing: 2
   aliquet: 1
   amet: 5
   ante: 2
   arcu: 1
   at: 3
   auctor: 2
   blandit: 3
   commodo: 2
   congue: 1
   consectetur: 3
   convallis: 2
   dapibus: 1
   diam: 4
   dictum: 1
   dolor: 5
   dui: 1
   eget: 3
   elementum: 1
   elit: 2
   erat: 1
   eros: 1
   est: 2
   et: 3
   eu: 4
   facilisis: 1
   faucibus: 3
   felis: 3
   fermentum: 1
   feugiat: 1
   fringilla: 2
   gravida: 3
   id: 2
   imperdiet: 3
   in: 4
   ipsum: 4
   justo: 3
   lacinia: 1
   lacus: 3
   laoreet: 2
   leo: 3
   libero: 1
   ligula: 2
   lorem: 1
   magna: 2
   malesuada: 3
   massa: 2
   mattis: 2
   mauris: 1
   metus: 2
   mi: 2
   molestie: 1
   nec: 3
   neque: 2
   nibh: 2
   nisi: 1
   non: 4
   nunc: 4
   odio: 1
   orci: 1
   ornare: 4
   pellentesque: 2
   pharetra: 2
   placerat: 4
   porta: 1
   purus: 2
   quam: 1
   quis: 4
   risus: 2
   rutrum: 2
   sagittis: 1
   sapien: 2
   sed: 8
   sem: 1
   sit: 5
   sollicitudin: 4
   suscipit: 1
   tellus: 3
   tempor: 2
   tempus: 1
   tincidunt: 3
   tortor: 3
   tristique: 2
   turpis: 1
   ullamcorper: 1
   ultrices: 1
   urna: 3
   vehicula: 1
   vel: 3
   velit: 1
   venenatis: 1
   vestibulum: 2
   vitae: 1
   viverra: 1
   volutpat: 2
   vulputate: 2
