#Q1
Le nom de chaque oiseaux : //espece/@nom

#Q2
Le nom d’image de chaque oiseau : //espece/@image

#Q3
Les Passeriformes (attention `a la majuscule) : cat //espece[ordre="Passeriformes"]/@nom

#Q4
Le second synonyme du premier oiseau : //espece[1]/synonymes/synonyme[2]

#Q5
Les oiseaux ayant au moins 5 synonymes : cat //espece[count(synonymes/synonyme)>4]/@nom

#Q6
Les oiseaux dont le nom contient ”accenteur” : //espece[contains(@nom,'accenteur')]

#Q7
Les  ́elements ayant 5 enfants : /oiseaux/descendant::*[count(descendant::node())>4]
