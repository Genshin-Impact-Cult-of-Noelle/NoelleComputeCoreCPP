import * as genshindb from "genshin-db"
import * as fs from "fs"
const RolePath = "..\\src\\lib\\Core\\DB\\Role\\"

genshindb.weapons("names",{ matchCategories: true }).map((i)=>{
    var w = genshindb.weapons(i, { resultLanguage: genshindb.Languages.ChineseSimplified })
    if(w?.name=="螭骨剑"){
        console.log(w);
        console.log(w.stats(90));
        

    }
    
})



// genshindb.weapons('names', { matchCategories: true }).map(name=>{

//   let data =  genshindb.weapons(name,{ resultLanguage: genshindb.Languages.ChineseSimplified })
// console.log(data?.substat,data?.stats(90)?.specialized);


// })
