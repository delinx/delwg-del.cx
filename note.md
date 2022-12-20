
### Nodes can include only other nodes
 * Node type can be set as Tag or Property
 <tag> </tag> and <property/>
 * Node can fit any amount of other Nodes within its storage vector
 * Oredr of nodes affects its render order
 * Parenting of nodes affect hierarchy 
 * When node is requested to convert itself to string it goes to all its children
 and requests them to do the same, up to the lowest layers, once deepest child is
 converted to text it goes back up the tree, resulting in a string consisting of 
 content of all its children
