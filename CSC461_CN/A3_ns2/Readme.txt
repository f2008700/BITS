Group members:

Mayank Singh - 	2008B3A7443G
Vikas Goel 	2008B3A7700G

1. First file contains the part of the code which does the broadcasting and routing table setup. Each node broadcasts the message to its neighbouring nodes and then update its corresponding routing table.
Execute it as:

ns <filename>.tcl <source node no.>
Example: ns final.tcl 13


2. Second file throughput analysis contains the functionality of calculating the throughput. Execute on terminal as:  

awk -f thruput.awk out.tr <press enter>
Enter source node: <node no.>     

awk is the command.
-f is the option used along the along.
thruput.awk is the file which contains the source code.
out.tr is the file on which we compute the throughput.
14 is the source from which the tcp/ftp connection is created (here it is 14).
destination node is assumed to be node 0 (for throughput analysis).

# The source node number should be the same as from which ftp/tcp is started

