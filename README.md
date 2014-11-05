LII-in-a-Box
============
	 	 	 

Functional Specifications for Legal Information Institute in a Box System Developed by the African Legal Information Institute


Introduction
============

Information systems designed for the legal information domain have been in existence since the early 1970s. Commercial publishers developed systems for searching within, initially indices of and subsequently full text, case law and legislation. Immediately following the introduction of new technology, researchers found difference in the quality of legal research conducted. An unexpected outcome of the introduction of this technology, was the possibility that opened up for allowing citizens access to the laws that govern them and the acts of the judiciary that applies those laws.
 
Well-developed computer-based legal information systems have always attracted significant investments in time and money. This was due to the highly specialized nature of the content being processed into those systems and the specialized skills required to develop and maintain them. The development cost has been and continues to be a significant barrier to both government and private projects to make the law available online.
 
Compounding the problem, most African countries suffer from shortages of IT skills, fast and accessible links to the Internet core, as well as reliable service providers offering advanced hardware for hosting solutions. This state of affairs had contributed to a rather slow adoption of technology for the dissemination of law on the African continent. A cursory look at the landscape of websites carrying legal information (both institutional and independent), confirms the veracity of this argument. However, this situation is changing fast.
 
The introduction and now widespread use of web content management system using standard, widely available and well-understood technologies have opened up opportunities for developing low-cost but high-impact technology solutions for disseminating and researching the law. AfricanLII has been experimenting, and subsequently operating in a production environment, legal information systems based on the Drupal CMS for the past 3 years. We have built into these websites industry standards for publication and dissemination of legal material, while still in keeping with the local requirements of each jurisdictions.
 
AfricanLII, through this project, will leverage the availability of resources and its own research and development activities over the past years to produce a  packaged software solution allowing for an easy installation of a localized legal information system . This solution will assist institutions with access to IT resources, who are not necessarily skilled in the specialized field of legal information systems, to deploy and successfully maintain such systems with minimal or no further support from AfricanLII. This will allow free law publishing projects, usually small entrepreneurial bootstrapped start-ups, to concentrate their initial efforts and resources on delivering much needed sustainable access to the law.

We thank the African Transparency and Technology Initiative, a joint fund of HIVOS and Omidiyar, for the opportunity to develop and deploy this system over the course of the next months.
Goals 

AfricanLII will develop a Drupal packaged distribution that powers up standards-based free and open access legal information websites. Drupal.org defines a distribution as: 

Distributions provide site features and functions for a specific type of site as a single download containing Drupal core, contributed modules, themes, and pre-defined configuration. They make it possible to quickly set up a complex, use-specific site in fewer steps than if installing and configuring elements individually.

The LII-in-a-Box will provide: 
1. Consumers of free legal information with a satisfactory and predictable user experience on desktop and mobile devices, based on industry standards for legal information publishing
2. System administrators with an easy and quick to set-up and maintain, no-cost, Drupal distribution for legal information publishing
3. Content editors of free and open access to law websites with a convenient editing back office interface that provides a set of custom-developed features that enable efficient upload and management of legal information.

Characteristics and Basic Components of the System
==================================================
 
An LII site must be able to present the information it carries in a way that is consistent with global standards for presentation of legal material; it must be researcher-friendly, i.e. able to provide a robust and extensive search interface; it must be user-friendly at multiple levels as it serves a market with varying technical skills. We have therefore already performed extensive customizations of Drupal to address some of these requirements.
 
The nature of law - as an ever changing and evolving body of rules contained in many types of documents - requires, that a legal information system is capable of adequately capturing both the hierarchical and temporal complexities of the law. To deal with these complexities, the legal information community has developed standards that deal with:
The arrangement of legal documents within national and international hierarchies;
The deletion, amendment and related temporal representation of legal documents within a national hierarchy, e.g. through the availability of current and historical versions of legislation;
The interconnection between sources of legal norms, cases, legislation, etc., and the practical implementation through corss-linking;
Referring to legal information in a standard way to ensure ease of re-use within documents of all kinds, but most importantly in other legal documents;
Retrieving legal information using fielded and full text searches.
 
All of these considerations around standards and functionality are accounted for in the design of the LII-in-a-Box


Intended producers and consumers of the data the system provides
=================================================================

The LII-in-a-Box is a standardized legal information publication platform intended to publish legal information in consolidated or final form as supplied by the producers of legal content - courts, legislatures, consolidators of laws, etc.

The primary target audience for the published information is the legal profession (lawyers, judges, government lawyers, legislation drafters, etc.), law librarians, law academics and students, as well as those professionals who regularly need access to the law. However, experience shows that the information on LII websites is often access and utilized by citizens, without necessarily having any qualifications in law, but who have had some encounter with legal problem that has lead them to do Internet research on the applicable law.

The first release of the LII-in-a-Box aims to facilitate the publication of the law for the ease and convenience of use of the primary audience of LII websites. However, the built-in standardization features would allow us to plan future modules that allow better citizen interaction with the law, as well as more sophisticated re-use of the data published via the system.

Our main objective currently remains enabling rapid and standardized publication of legal information by organizations who wish to do so on a minimal budget and minimal IT resources.


Activities supported by the system
==================================

The LII-in-a-Box system will support primarily the publication and reading of judgments, primary and secondary legislation, with modern search features both within and across individual collections. Other legal information content will be supported via standardized and built-in content types. However, and considering the variations across jurisdictions, we do not aim to be exhaustive in the provision of options.

Both per-item and bulk uploading options will reduce the editorial burden on legal information publishers.

The LII-in-a-Box system will provide a standardized interface into legal information published and stored within. Thus, where license is granted by the publisher, the development will assist the easy reuse of content. This will primarily be achieved via the deployment of a standardized URI structure for web and associated files content, as well as via various pre-defined RSS streams.


Data, data structure and information retrieval
==============================================

The LII-in-a-Box system will capture only a portion of the complex multi-layer information architecture of a legal document (as per Palimarani, et al) :
the text - part of the document officially approved by the authority with legal power, and
the metadata: any information that describes the legal document. The metadata can involve document description metadata (e.g. keyword), workflow (e.g. procedural steps in the bill), lifecycle of the document (e.g. history of the document over the time), document identification metadata (e.g. URL, URI, URN and annexes).

In a foreseeable future release of the system, we also plan to include structural data - part of the document that states an organization of the text, to allow for a better user interface and re-use of information.

The system will store data in a variety of formats - html, pdf, Office version (doc, docx, rtf) at minimum. The data will be classified into content types, depending on the type of document uploaded. Additionally, taxonomies will provide further classification granularity.

General and advanced searches will aide the retrieval of information. The general search will enable users’ Boolean or natural language search within all of the website’s content, including non-legal information, but search results will provide the option of narrowing down the search results via assigned categories. Advanced search, on the other hand, will allow users to narrow down search using pre-defined Boolean search fields, coupled with search into categories of content.


Specifications and Components
=============================
The system as being defined by the following basic considerations:
1. It must contain defined content types - judgment, consolidated legislation, sessional laws, parliamentary debates, bills, government gazette, journal, etc.- which are common across countries and legal systems, albeit subject to localized customizations;
2. It must allow for content negotiation, i.e. to facilitate the output of legal information in a wide range of formats;
3. The content must be captured using a metadata model, incorporating current recognized standards all with the aim of enabling advanced version control and output of descriptive metadata;
4. It will employ a PRESTO architecture, which we currently strive to implement, and which is a combined use of Permanent URIs, Representational State Transfer (REST), and object-oriented design and modelling
5. It is mobile-ready.
All Drupal customizations will be carried out with a view to providing mobile/smart phone access alternatives to users. At present mobile penetration is surpassing Internet penetration in most African countries by a sizable margin. This has the effect that the majority of our users will be using mobile devices to access African LII websites. All information must therefore be able to be presented in such a way as to facilitate access to the core information by users but also to allow for the development of mobile applications which will make use of this information.


Updates and corrections to the data post initial upload
=======================================================
Data on the system will be uploaded either manually or in batch uploads, initiated by the website editors or administrators. Data can be corrected post-inital publication and a record of each version will be kept by the system, but will not be made available to users by default.

The system keeps record of the publication time of each correction. This is important as it substantively affects the application of legal rules contained within sources of law published.

System maintainers profiles
===========================

At minimum the staff required to maintain the system consists of Content Editors, whose main responsibility will be to upload and correct content on the system. Content Editors should have, at minimum, received training in the types of legal documents in a jurisdiction, the various metadata that describes them and the construction of references for the types of documents.

The Content Editors would ideally be supported by a System Administrator/Drupal web developer, whose responsibility would be the installation, maintenance and design modifications (if required) of the local installation of the LII-in-a-Box and the web server employed by the organization. However, if such skills do not exist at the organization, AfricanLII will be available to provide such support, including hosting, at minimal cost.


Who is this sytem for?
=====================

The LII-in-a-Box is intended to server all those projects and institutions, who wish to publish the law they produce or collect for publication for free online access. The type of institution that could benefit from the LII-in-a-Box ranges from courts, legislation producers (Parliament, Attorney General’s offices), law reform commissions, to external institutions or projects that collect legal information from the producers and consolidate it into one platform, using the LII-in-a-Box.



Definitions 
===========
Judgment
- a decision of a law court or a judge

Legislation (or statute) as promulgated
- the laws passed by the law-giving agency of the land (e.g. Parliament), which have not been editorially amended or annotated to indicate status of legal provisions, e.g. an Act of Parliament as promulgated, is published under the Legislation content type in the LII-in-a-Box system

Consolidated legislation 
Versions of acts and regulations that include amendments made after their original enactment and which are currently in operation. Consolidations may have been performed by a statutorily appointed body or by an independent editor. 

Government Gazette 
The publication (gazette) of record in a particular jurisdiction. The Gazette publishes the official versions of legislation, notices in terms of legislation, proclamations, and other relevant legal information. 
Subordinate legislation
Laws made under delegation from the law-giving agency of the land. Examples include statutory instruments, regulations, proclamations, local and municipal laws
Bill
Proposed legislation. 

Journal article
A scholarly publication in the field of law, appearing in a formal publication, known as Journal.

Full-text search
Search within the entire text of a document or documents published on the website. Includes web pages, PDF and text-based files. Does not search within metadata.

Fielded search
Allows users to limit their search to the metadata of documents published on the system.

User Roles and Functionality of the System 
==========================================
All users can
All users - authenticated or anonymous - can access and utilize the following resources and services on the LIi-in-a-Box instance:
Access the Main page
- Read news
News are blog posts authored by the site’s Editors, which appear under a separate section of the website. 

- Read significant recent additions
Significant recent additions is a list of hyperlinks manually selected and collated by the site’s Editors. They usually highlight interesting cases or legislation posted on the website.

- Read useful links
Useful links is a selection of links to external resources, curated by the site’s Editors.

- Access public menus to publicly available content
Public menus are links visible to all users of the website and offer access only to freely and openly available content. 

- Perform full text search into available site content or in specific categories of legal content types
See Search functionality below. 

- Access About us, Terms of Use and Blog/Site news pages
These are static pages, which do not contain legal information, modified from time to time by Content Editors.

- Access Contact form
The Contact form allows all users to reach the website owners while the owners’ email addresses remain protected. 

`Access all Caselaw databases`

Utilize all caselaw available via the system, which has been marked by Content Editors as published. There are several ways to enable users to browse content on a specific caselaw database, and this is achieved through alphabetical and chronological indices. Therefore all users can:

View index/landing page with chronological ( per year) and alphabetical arrangement  (ascending alpha order) of available caselaw 

View Alphabetical arrangement of caselaw per court per letter - ascending order, per letter A and further alphabetize within the group 


View Chronological arrangement of caselaw per court and per month - group chronologically within monthly category; if two cases within a month have the same date - arrange alphabetically 


Alphabetical and Chronological listings of case titles will be displayed to users in the format, and will be linked to a HTML page of the case, as per the example below

Example:
=======
<Case name> (<case number>) <MNC> (<judgment date>); <additional citation> (for common law jurisdictions)
E.g. Anti-Corruption Commission v Serioes Farms Limited (SCZ/8/199/2009) [2014] ZMSC 35 (6 January 2014); Appeal No. 155/2009 

<case subject area or case title> <case number> <judgment date>; <MNC> (for civil law jurisdictions)


`Case page`
The case page is a dedicated web resource providing access to a judgement’s text, metadata and associated files. 

View breadcrumbs organized in the format: 

Home » <Name of Court> » <year of judgment> » <MNC> » <title of judgment>
Home » <collection> » <year> » <title>

View the full case title at the top of the page

View public metadata for judgment, which is:
- Case name
- Case number
- MNC
- Judgment date
- Additional citation
- Related judgments or legislation


View taxonomy classification of the judgment

View and download available file formats - PDF, doc, docx, rtf, or odt - versions of judgment

View full text of judgment as HTML page

View/follow hyperlinks within the HTML text of the judgment to other judgments or legislation on the system 

View links to cases and legislation, cited within the body of the text of the judgment 



`Legislation database`

The Legislation page is a dedicated web resource providing access to legislation’s text, metadata and associated files. There are two types of legislation content types - Consolidated legislation and Numbered acts.


`Consolidated legislation`

View index page with legislation arranged in alphabetical order A-Z, and alphabetized within each group

View title of legislation on each page in the format prescribed for citation of that type of legislation in the particular jurisdiction

Title of legislation is linked to URL of HTML version of legislation

View full text of particular document in HTML

View date of consolidation

View and download PDF, doc, docx, rtf, or odt version of document

View / follow links to related other legislation, caselaw or legal documents



`Numbered acts (legislation as promulgated)`

View index page with legislation arranged in alphabetical and chronological order (per year)

Chronological index per year lists legislation in alphabetical order within the group

View title of legislation on each page in the format prescribed for citation of that type of legislation in the particular jurisdiction

Title of legislation is linked to URL of HTML version of legislation

View full text of particular document in HTML

View the following publicly available metadata:
long title
short title
status (in force or not)
date of assent
commencement date

View and download PDF, doc, docx, rtf, or odt version of document

View / follow links to related other legislation, caselaw or legal documents


`Bills of Parliament`

View index page with bills arranged in alphabetical and chronological order (per year)

Chronological index per year lists bills in alphabetical order within the group

View title of bill on each page in the format prescribed for citation of that type in the particular jurisdiction

Title of bill is linked to URL of HTML version of document

View full text of particular document in HTML

View the following publicly available metadata:
Short title
Long title
date introduced
sponsor

View and download PDF, doc, docx, rtf, or odt version of document

View / follow links to related other legislation, caselaw or legal documents


`Other legal content types`

View document title in a chronological/alphabetical index

View text of document

Download alternative file formats

View related documents on the system 


**Authenticated users can:**
Authenticated users are those users of the website, who have successfully completed the registration process prescribed by the website administrators. Additional to the above privileges, they can: 


View any content available to anonymous users

View all recent content posted on the website

View and amend their user profile

Contact other LII users

Subscribe to email alerts for new content (select content categories to subscribe to)

Subscribe to newsletter

View other custom available content or services as determined by the Editor



**Editor users can**
The Editors (or Content Editors) are a category of users, with exclusive permissions to add, amend and delete website content. 

View all content and utilize all services available to anonymous and authenticated users

View full metadata of all content uploaded on the system

Import content in bulk

Create, amend and delete their own content as per set content types

Attach files to created content

Administer user registrations

Administer the feed aggregator

Manage the Significant Recent additions queue 



 


**Site administrators can**
Site administrators usually perform a more technical function than that of Content Editors, such as adjusting various settings, installation of external modules, troubleshooting, etc. 

Has all access privileges as the Editor user

Has access to all features of the Drupal administration menu. 

Can create and modify content and content types

Can manage users and user permissions

Can administer Site building and Site configuration 

Can manage file sizes and permissions





**Content types**

In Drupal, a Content Type is a pre-defined collection of data types (Fields) which relate to each other by an informational context. In this sense, "context" means "parts that should be considered as a correlated whole." Content Types are how site editors can input original content on a Drupal site. Drupal ships with standard content types called Page and Story. Additional content types, such as Blog, Book, Poll, etc. could be installed as optional core content types. Content types are useful in many respects, including to organize content from a site administrator’s and a user’s perspective, and for administering content permissions. 

The LII-in-a-Box will come standard with a number of pre-defined content types, and associated metadata fields. The content types are based on the most common document types published on legal information systems in both common law and civil law countries. Any other content will be captured under the “Other” content type.
Content type: Judgment

**Content type: Judgment**

<img src="http://www.africanlii.org/images/africanlii_logo.jpg" width="240" height="180" border="10" />

Content type: Legislation as promulgated

Content type: Consolidated legislation


Content type: Subordinate legislation

Content type: Bill


Content type: Journal article

Content type: Government Gazette Issue


Content type: Other


Content structure
The site’s content structure, therefore, consists of site information (non-legal) content, and legal information content, as per the content types. It is organized as follows:  



Categorization
The LII-in-a-Box will categorize content according to the following taxonomies:
Name of court for judgments content types
Subject matter for all content type
Author for journal content type
Categorization is useful for the browsing and searching of legal information content on the website.

Search
LII-in-a-Box will offer users two search facilities - Basic search and advanced search.

The Basic search would allow any user to perform a search within all content listed on the website. The Basic search box will be available on the Home page and on the sidebar of inner pages.

The Advanced search would allow any user to do the following: 
perform a Boolean logic search
search within categories of information (as per taxonomy)
search within specified content types
search for specific documents based on metadata, e.g. case number, citation, etc., i.e. provide fielded search into metadata 

By default, the search results will be displayed in order of relevance, with the most relevant result appearing on top of the search list. 

All users will have the option to sort the results in an alphabetical and chronological order. 

URI structure 
The URI structure of content will follow closely key metadata elements associated with the published document. 
LII-in-a-Box, similarly to legislation.gov.uk, attempts to follow the guidance given in How to Publish Linked Data on the Web in constructing identifier URIs. 

Identifier URIs for the separate content types generally are of the structure, as follows: 

Judgment

http://www.{sitename}.{org/.com}/{ISO_country code}/judgment/{name-of-court}/{year of decision date}/{sequential number of judgment}

Legislation as promulgated

http://www.{sitename}.{org/.com}/{ISO_country code}/legislation/act/{year enactment}/{sequential number of act as per assignment}


Consolidated legislation
http://www.{sitename}.{org/.com}/{ISO_country code}/legislation/consolidated-act/ {chapter number or sequential number or title}

Subordinate legislation
http://www.{sitename}.{org/.com}/{ISO_country code}/legislation/{abbreviation of subordinate legislation type name} / {year enactment}/{sequential number of subordinate legislation as per assignment}

Bill
http://www.{sitename}.{org/.com}/{ISO_country code}/legislation/bill/ {year enactment}/{sequential number of bill as per assignment}

Journal article

http://www.{sitename}.{org/.com}/{ISO_country code}/journal/{abbreviation journal title} /{year of publication}/{sequential number or other identifier or  title}

Government Gazette Issue

http://www.{sitename}.{org/.com}/{ISO_country code}/{abbreviation of title of governemnt gazette}/{year of publication}/{issue number}/

Other
http://www.{sitename}.{org/.com}/{ISO_country code}/other/{abbreviation issuing body name} / {type of document}/{year of publication by issuing body}/{sequential number or title}

Generic, non legal information, content

http://www.{sitename}.{org/.com}/content/{publication date}/{title-of-page}

File path structure

For ease of management and for user convenience, files associated with content on the LII-in-a-Box  platform will be stored in location with URIs identical to the URIs of the main piece of content, followed by the filename and extension. 


For example, for judgments, the filename, in variety of formats, would follow the closing of the URI of the main resource, hence

URI for main resource: http://www.{sitename}.{org/.com}/{ISO_country code}/judgment/{name-of-court}/{year of decision date}/{sequential number of judgment} 

URI for PDF: http://www.{sitename}.{org/.com}/{ISO_country code}/judgment/{name-of-court}/{year of decision date}/{sequential number of judgment}/{filename.pdf}

URI for RTF: http://www.{sitename}.{org/.com}/{ISO_country code}/judgment/{name-of-court}/{year of decision date}/{sequential number of judgment}/{filename.rtf}


Automated linking

Where possible, the LII-in-a-Box platform will parse and automatically hyperlink titles and citations of cases and legislation available on the same website. 

For example, if a court judgement refers to a another judgment in a standard format (the prevalent citation method of the jurisdiction), the LII-in-a-Box shall automatically hyperlink the citation and lead the user to the referred to document. Similarly, if a document refers to a piece of legislation by its title or officially adopted citation for the jurisdiction, the reference will be hyperlinked to the actual document on the website.

This will present a considerable improvement in users’ navigation of the LII websites. 

	 	 	
System Architecture
Major tasks to be performed.
	
Implement base open source framework and configure it for base server requirements and implement and ensure canonical URLs work.
Ensure world class security exists for database connection library and implement 	any tunnel / data encryption as deemed necessary by various South African legislation, for initial launch and upkeep of the framework and all modules. In addition, implement a normalised database schema design.
Implement an expandable and easy to use hierarchical permission system that will serve the categories of users as per the functional specification. 	
Implement content versioning / auditing for easy rollback / re-use of content.
Develop a Content import / export module for LII websites and package into the LII-in-a-Box distribution. 
Ensure valid XHTML formatting exists.
Enhance content capturing with a rich text editor. 
Ensure that CSS is minified with Javascript libraries for quick load times on the 	site and lower processing power on the hardware on which the site will be hosted.
Automatic sitemap generation for public and SEO uses.
Automatic google analytics integration. 
Automatic creation of RSS feeds for news and any content that is deemed 		necessary. 
Search functionality needs to serve the entire CMS system database and assets that are loaded onto the site.
Ensure full SEO compliance.

System Functions
	
Implements the functional requirements
Provides an easy to deploy and customize specialized legal information publication system via
a packaged distribution containing Drupal core, plus custom developed modules
prompts allowing easy customization of key features relating to presentation of legal information
detailed technical and editorial documentation to install and maintain the deployed website

Software Architecture
The system will be based on Drupal 7.x content management framework. The codebase will then be stored on GitHub to allow for extensions and further development of the system.

The framework requires the following to be loaded and working on the server hosting infrastructure:	
	
PHP	
MySQL (PDO)	
PHP Modules		
PHP-XML			
PHP-SOAP		
PHP-MySQLi			
PHP-GD
JQuery

Current software settings
See Appendix A

Flow chart of Installation of LII-in-a-Box from a System Administrator perspective


Quality Attributes (Non-functional Requirements)

Performance
Site needs to maintain a grade B or better YSlow loading index. YSlow indexes and profiles page load and network waits for content displayed on the site. It analyses JS and CSS loading and optimization and provides solutions to increase grading. This assists with a fast and lean load to the end user and is especially important with a system based on database content.

Reliability
The system shall be accessible at any time, with the exception of technology infrastructure failure.

Availability
System availability is usually defined as "the degree to which a system suffers degradation or interruption in its service to the customer as a consequence of failures of one or more of its parts". In other words, it is the amount of time a system is available and ready for use.

Security
All content and media loaded into the site must pass a internal core validate and filter processor this allows elimination of Blind SQL injection, SQL injection, Cross side scripting, Data spoofing.

Maintainability
The system shall be easily maintainable by the administrator through the use of system user interface. Also, other programmers shall be capable of easily modifying and updating modules by using the documentation provided with the system.

The entire content related aspect of the site needs to be easily and intuitively maintained by the site content editor(s).

Portability
The system shall be portable to enable other LII's to download and install in their platform that meets the requirements that will be stipulated.



Extensibility
The system shall be extensible through the use of required software. Code and modules need to be extendable and allow a seamless integration of all aspects of the system into modules and use of all core features of the system by developed modules.

All future modules developed have to conform to coding standards and documentation requirements for the site.

Application Affinity/Compatibility
The system shall be compatible with any of the following Internet browsers: All mainstream and currently supported browsers on Windows, Linux and Apple platforms.

Resource Utilization
The system shall be accessible from any type of desktop computer with an active Internet connection. The system shall require an active server with adequate hard drive space and available memory

Serviceability
The system shall be easily modified by referencing the documentation that shall be provided within the code – in standardized formatting.


Appendices
Appendix A
Drupal Version: 6.29.
The table below shows the modules that are currently installed and will be reviewed, incorporated or upgraded, and released as part of the distribution LII-in-a-Box.

Module
Version
Description
Comment
Apache Solr
		
6.x-1.6
		
Framework for searching with SOLR
Requires installation of SOLR on the web server	
CCK
		
6.x.2.9
		
Content Construction Kit allows you to add custom fields to nodes	
Used for creating new content types
Core
		
6.x
		
			

			
		
			

			
		
Custom Search
		
6.x-1.9
		
This module alters the default search in customizable ways
			
		
Date
		
6.x-2.4
		
Module provides a flexible date/time field type, Date field and a Date API that can be used by other modules
Being 	used by CCK for creation of date field content types
Glossify
		
6.x-2.5
		
Automatically links nodes in your site according to your settings – parses 	node bodies searching for titles of other nodes
		
Used to automatically interlink caselaw and legislation. For example, where and Act refers to another Act and that Act exists on the system, the link to it will be automatically inserted		
Simplehtmldom
		
6.x-1.12
		
A wrapper module required by Glossify
	
Finder
		
6.x-1.19
		
Allows Drupal site administrators to create flexible faceted search forms
			
Nodequeue
		
6.x-2.11
		
Create queues which can contain nodes in arbitrary order	
			

			
		
Caseimport
		
			
		
Custom module created by AfricanLII for bulk import of case law. Still under development.	

			
		
CCK Field Indexer
		
6.x-1.0
		
Allows the indexing of CCK fields into the search index


			
		
DB Maintenance
		
6.x-1.3
		
Executes an OPTIMIZE TABLE query on MyISAM, InnoDB, or BerkeleyDB database tables in a MySQL database.
			

			
		
IndexPage
		
6.x-1.1
		
This module displays customizable index pages for each node type, with alphabetical and taxonomy filters.
Used for index pages for legislation content types. Still to be customized for case law pages.
		
Keyword Link
6.x-1.x-dev
A module that allows you to define keyword/link pairs. The keywords are automatically linked in each of your posts. This is useful for improving the internal cross referencing pages inside your site or to automatically link to external partners (SEO).
Implemented as an alternative to Glossify
		
Internationalization
		
			
6.x-1.10
		

Extends Drupal support for multilingual features
		
			
Used 			for sites in bilingual jurisdictions, e.g. Mozambique
		
			
PathAuto
		
			
6.x-1.6
		

Provides a mechanism for modules to automatically generate aliases for the 			content they manage
		
			
Required 			for URL Aliasing
		
			
RobotsTxt
		
			
6.x-1.2
		
			
Generates the robots.txt file dynamically and gives you the chance to edit it, on a per-site basis, from the web UI.
		
			
Required 			because the multisite implementation default is a shared 			robots.txt file
		
			
Shiny_upload
		
			

			
		
			
Displays file attachments nicely
		
			

			
		
			
Token
		
			
6.x-1.18
	
			
Provides a shared API for replacement of textual placeholders with actual 			data
		
			
Required 			for URL Aliasing.
		
Token Actions
		
6.x-1.18
		
Provides enhanced versions of Drupal core actions using the Token module.
			

			
		
TokenSTARTER
		
6.x-1.18
		
Provides additional tokens and a base on which to build your tokens.	
			

			
		
UploadPath
		
6.x-1.0
		
Organize uploaded files according to admin-specified rules	
			

			
		
Captcha/ Re-captcha
		
6.x-2.4
		
Adds challenges to forms to filter out spambots
		
			

			
		
CKEditor
		
6.x-1.8
		
Enables Wysiwyg editor for use instead of plain text fields	
			

			
		
JqueryUI
		
6.x-1.5
		
Provides the Jquery UI plugin module to other Drupal modules	
			

			
		
JqueryUpdate
		
6.x-2.0-alpha1
		
Updates Drupal to use the latest version of JQuery
		
			

			
		
Views
		
6.x-2.16
		
Create customized lists and queries from your database
Being used for experimental purposes	
Webform
		
6.x-3.15
		
Enables the creation of forms and questionnaires
			

			
		
XML sitemap
		
6.x-2.0-rc1
		
Creates an XML sitemap according to the sitemaps.org protocol
		
			

		


