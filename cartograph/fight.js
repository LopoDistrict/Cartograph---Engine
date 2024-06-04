
                
                        
                        function critical(crit){
                            return Math.random() <= crit;
                        }
                        function ennemy_variation(life, dmg, def, player_lvl){
                            ennemy_life = life * 0.40 * player_lvl,
                            ennemy_dmg = dmg *0.30 * player_lvl;
                            ennemy_def = def * 0.30 * player_lvl;
                        }

                        // Parse the query string to retrieve the argument
                        const queryString = window.location.search.substring(1);
                        const argPair = queryString.split('=');
                        const argKey = argPair[0];
                        const argValue = decodeURIComponent(argPair[1]);
                        console.log(`${argKey}: ${argValue}`)

                    
                        

                        var player_lvl= 0; //temp var until i upload player_stats.json
                        var player_defense= 0;
                        var player_life= 0;
                        var player_name= "";
                        /*
                        async function loadJsonData() {
                            console.log("start");
                            try {
                                const response = await fetch('json/ennemy_data.json'); // Assuming data.json is in the same directory
                                const jsonData = await response.json();

                                for (const key in jsonData) {
                                    console.log("in");
                                    console.log("key " + key);
                                    console.log(jsonData.key[1].name)
                                    console.log(jsonData[key].name)
                                    if (key == argValue){
                                        console.log(matchingItem);  
                                        ennemy_name = jsonData.enemies[key].name;
                                        ennemy_life = jsonData.enemies[key].life;
                                        ennemy_dmg = jsonData.enemies[key].dmg;
                                        ennemy_def = jsonData.enemies[key].defense;
                                        console.log(key)
                                        console.log(ennemy_name)
                                        console.log(ennemy_life)
                                        console.log(ennemy_dmg)
                                        console.log(ennemy_def)
                                    }
                                }
                                
                                
                                
                            } catch (error) {
                                console.error('Error loading JSON data:', error);
                            }
                            }

                        */
                        var ennemy_name = "";
                        var ennemy_life = 0;
                        var ennemy_dmg = 0;
                        var ennemy_def = 0;
                        var ennemy_crit = 0;

                       const fs = require('fs');
                       const jsonData = JSON.parse(fs.readFileSync('json/ennemy_data.json', 'utf8'));
                        for (let i of jsonData.enemies) {
                            if (i.id === argValue) {
                                ennemy_name = i.name;
                                ennemy_life = i.life;
                                ennemy_dmg = i.dmg;
                                ennemy_def = i.defense;
                                ennemy_crit = i.crit;
                                break;
                                
                            }
                        }

                    const fs2 = require('fs');
                       const jsonData2 = JSON.parse(fs2.readFileSync('json/player_stats.json', 'utf8'));
                        for (let j of jsonData2.Stats) {  
                                player_name = j.name;
                                player_life = j.health;
                                player_defense = j.defense;
                                player_lvl = j.level;
                                total_life = j.health;
                                //player_ = i.crit; // implémente crit
                                break;
                                
                        }

                        ennemy_variation(ennemy_life, ennemy_dmg, ennemy_def, player_lvl);
                        const total_ennemy_life = ennemy_life;
                        document.getElementById("life_ennemy").innerHTML = ennemy_life + "/"+ total_ennemy_life;
                        document.getElementById("life_player").innerHTML = player_life + `/${total_life}`;


                        var turn = 1;

                        function ennemy_attack(name, ennemy_dammage){
                            if (critical(ennemy_crit) == true){
                                var temp_dmg = (Math.floor(Math.random() * (ennemy_dammage + 5 - ennemy_dammage + 1)) + ennemy_dammage) + 5; 
                            }else{
                                var temp_dmg = (Math.floor(Math.random() * (ennemy_dammage + 5 - ennemy_dammage + 1)) + ennemy_dammage);
                            }
                            
                            turn = 1;
                            player_life -= temp_dmg;
                            document.getElementById("turn_id").innerHTML = player_name+"'s turn";
                            document.getElementById("life_player").innerHTML = player_life + `/${total_life}`;
                            document.getElementById("log").innerHTML = `You got hit by ${ennemy_name} for ` + temp_dmg;
                        }


                        function simple_attack(name, dammage){
                            if (turn == 1){
                                
                                var atk_val = (Math.floor(Math.random() * (dammage + 5 - dammage + 1)) + dammage) + (ennemy_def);
                                ennemy_life -= atk_val;
                                
                                
                                hiding('toHide','shower_sa', 'hider1' )

                                turn = 2;
                                document.getElementById("turn_id").innerHTML = `${ennemy_name}'s turn`;
                                document.getElementById("life_ennemy").innerHTML = ennemy_life + "/"+ total_ennemy_life;
                                document.getElementById("log").innerHTML = `You hit ${ennemy_name} for ` + atk_val;
                                setTimeout(function() {ennemy_attack("toxic cough", 4);}, 2000);
                                                    
                                

                        }
                    }    
                        
                    const fs3 = require('fs');
                    const atkData = JSON.parse(fs3.readFileSync('json/player_stats.json', 'utf8'));
                    const atk = atkData.equipment[0].weapon;
                    console.log(atk);
                    let attaque_json = [];
                    var atk2 = document.getElementById("atk2");
                    var atk3 = document.getElementById("atk3");

                    for (let i=0; i<atk.length; i++){
                        console.log(i);  
                        console.log(atk[i]);
                        attaque_json.push(atk[i]);
                        console.log( "attaque_json.length"+ attaque_json.length);                    
                        
                        // la fonction peut gérer 2attaque
                        // pour en gerer plus mettre 9 et ajouter une div atk3
                        if (attaque_json.length % 6 === 0){ 
                            console.log("start")
                            atk2.style.display = "block";
                            atk3.style.display = "block";

                            //document.getElementById("atk3").onclick = simple_attack('smash', 100);
                            atk3.onclick =`simple_attack(${attaque_json[4]},${attaque_json[3]})`;

                            document.getElementById("title-entity2").innerHTML = attaque_json[1];
                            document.getElementById("title-entity3").innerHTML = attaque_json[4];

                            document.getElementById("desc2").innerHTML = attaque_json[2];
                            document.getElementById("desc3").innerHTML = attaque_json[5];
                            console.log("creating...");                            
                            

                        }

                    }
                        // click en attaque hide le menu et show les attaque dispo


                            function display(hide, show, hider){
                                const to_hide = document.getElementById(hide);
                                to_hide.style.display = "none";
                                // hiding

                                const to_show = document.getElementById(show);
                                to_show.style.display = "block";

                                const button = document.getElementById(hider);
                                button.style.display = "block";
                            }


                            function hiding(show, hide, hider){
                                const to_hide2 = document.getElementById(show);
                                to_hide2.style.display = "block";
                                // hiding

                                const to_show2 = document.getElementById(hide);
                                to_show2.style.display = "none";

                                const button2 = document.getElementById(hider);
                                button2.style.display = "none";
                            }

                        