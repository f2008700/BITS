string=[]
arr=[]
for i in range(0,120):
	string.append(str(i)+'.txt')
	int(i)
	f=open(string[i],"r")
	arr.append(f.read())

#for i in range(0,120):
#	print arr[i]

from gensim import corpora, models, similarities

documents=[]
for i in range(0,120):
	documents.append(arr[i])
	
# remove common words and tokenize them
stoplist = set('for a of the and to in '.split())
texts = [[word for word in document.lower().split() if word not in stoplist]
         for document in documents]

#remove words that appear only once
all_tokens=sum(texts,[])
tokens_once=set(word for word in set(all_tokens) if all_tokens.count(word)==1)
texts=[[word for word in text if word not in tokens_once]
	for text in texts]
	
#print texts	

dictionary = corpora.Dictionary(texts)
dictionary.save('/tmp/deerwester.dict') # store the dictionary, for future reference
#print dictionary

print dictionary.token2id

print ""
print "Please enter the query: "
new_doc=raw_input()
new_vec=dictionary.doc2bow(new_doc.lower().split())
print new_vec

corpus = [dictionary.doc2bow(text) for text in texts]
corpora.MmCorpus.serialize('/tmp/deerwester.mm', corpus) # store to disk, for later use
print corpus

tfidf = models.TfidfModel(corpus)

print "tfidf[vec]--->>"
print tfidf[new_vec]

index = similarities.SparseMatrixSimilarity(tfidf[corpus])

sims = index[tfidf[new_vec]]
print "list(enumerate(sims))"
print list(enumerate(sims))
